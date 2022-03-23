#include "treap.h"

#include <stdlib.h>
#include <stddef.h>


struct treap_node {
    struct treap_node *lo;
    struct treap_node *hi;
    struct treap_node *up;

    int priority;
    char data[0];
};

struct treap {
    int count;
    int ksize;
    int vsize;
    treap_cmpfunc *cmpfunc;
    struct treap_node *root;
};

static int treap_kbyref(const struct treap *self) {
    return self->ksize == 0;
}

static int treap_hasval(const struct treap *self) {
    return self->vsize >= 0;
}

static int treap_vbyref(const struct treap *self) {
    return self->vsize == 0;
}

static int treap_kdatasize(const struct treap *self) {
    if (treap_kbyref(self)) 
        return sizeof(void*);
    else
        return self->ksize;
}

static int treap_vdatasize(const struct treap *self) {
    if (!treap_hasval(self))
        return 0;
    else if (treap_vbyref(self))
        return sizeof(void*);
    else
        return self->vsize;
}

static int treap_datasize(const struct treap *self) {
    return treap_kdatasize(self) + treap_vdatasize(self);
}

static void* treap_node_kpos(const struct treap *self, const struct treap_node *node) {
    return node->data;
}

static void* treap_node_vpos(const struct treap *self, const struct treap_node *node) {
    return node->data + treap_kdatasize(self);
}

static void* treap_node_kptr(const struct treap *self, const struct treap_node *node) {
    void *kpos = treap_node_kpos(self, node);
    if (!treap_kbyref(self))
        return kpos;
    else
        return *((void**)kpos);
}

static void* treap_node_vptr(const struct treap *self, const struct treap_node *node) {
    if (!treap_hasval(self)) return NULL;

    void *vpos = treap_node_vpos(self, node);
    if (!treap_vbyref(self))
        return vpos;
    else
        return *((void**)vpos);
}

static void treap_node_storekey(const struct treap *self, const struct treap_node *node, void *key) {
    void *kpos = treap_node_kpos(self, node);
    if (treap_kbyref(self))
        memcpy(kpos, &key, treap_kdatasize(self));
    else
        memcpy(kpos, key, treap_kdatasize(self));
}

static void treap_node_storeval(const struct treap *self, const struct treap_node *node, void *val) {
    if (!treap_hasval(self)) return;

    void *vpos = treap_node_vpos(self, node);
    if (treap_vbyref(self))
        memcpy(vpos, &val, treap_vdatasize(self));
    else
        memcpy(vpos, val, treap_vdatasize(self));
}

static struct treap_node* treap_node_create(const struct treap *self, void *key, void *val) {
    struct treap_node *node = (struct treap_node*) malloc(sizeof(struct treap_node) + treap_datasize(self));

    node->hi = node->lo = node->up = NULL;
    node->priority = rand();

    treap_node_storekey(self, node, key);
    treap_node_storeval(self, node, val);

    return node;
}

static struct treap_kvpair treap_node_kvpair(const struct treap *self, const struct treap_node *node) {
    if (node == NULL) {
        return (struct treap_kvpair) {
            .isvaild = 0,
            .key = NULL,
            .value = NULL
        };
    }
    else {
        return (struct treap_kvpair) {
            .isvaild = 1,
            .key = treap_node_kptr(self, node),
            .value = treap_node_vptr(self, node)
        };
    }
}




struct treap* treap_create(treap_cmpfunc *cmpfunc, int ksize, int vsize) {

}


struct treap* treap_duplicate(const struct treap *self) {

}


void treap_destroy(struct treap *self) {

}


int treap_count(const struct treap *self) {
    return self->count;
}


void treap_insert(struct treap *self, const void *key, const void *val) {

}


int treap_remove(struct treap *self, const void *key) {

}


struct treap_kvpair treap_lookup(const struct treap *self, const void *key) {

}


void treap_union(struct treap *self, const struct treap *other) {

}


void treap_intersection(struct treap *self, const struct treap *other) {

}


void treap_difference(struct treap *self, const struct treap *other) {

}


void treap_foreach(const struct treap *self, treap_foreachfunc *func) {

}


void treap_map(struct treap *self, treap_mapfunc *func) {

}


void treap_toarray(const struct treap *self, void **buf, int *len) {

}
