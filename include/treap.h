/* Copyright (c) 2022 -- Alexander Schneiders -- MIT License */
#ifndef TREAP_H
#define TREAP_H


typedef int (treap_cmpfunc)(const void*, const void*);
typedef void (treap_foreachfunc)(const void*);
typedef void* (treap_mapfunc)(const void*);



struct treap {
    const treap_cmpfunc *cmpfunc;
    const size_t count;
};


extern struct treap treap_create(treap_cmpfunc *cmpfunc);

extern struct treap treap_duplicate(const struct treap *self);

extern void treap_destroy(struct treap *self);

extern void treap_insert(struct treap *self, void *obj);

extern void treap_remove(struct treap *self, void *obj);

extern int treap_contains(struct treap *self, void *obj);

extern void treap_union(struct treap *self, const struct treap *other);

extern void treap_intersection(struct treap *self, const struct treap *other);

extern void treap_difference(struct treap *self, const struct treap *other);

extern void treap_foreach(const struct treap *self, treap_foreachfunc *func);

extern void treap_map(struct treap *self, treap_mapfunc *func);

extern void treap_toarray(const struct treap *self, void **buf, int *len);


#endif /* TREAP_H */