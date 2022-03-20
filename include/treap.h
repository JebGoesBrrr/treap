/* Copyright (c) 2022 -- Alexander Schneiders -- MIT License */
#ifndef TREAP_H
#define TREAP_H


typedef int (treap_cmpfunc)(const void*, const void*);
typedef void (treap_foreachfunc)(const void*);
typedef void* (treap_mapfunc)(const void*);


/**
 * @brief   Treap (tree + heap) data structure.
 * @details A treap stores an ordered set of keys (and optionally associated values)
 *          and has high probability to have O(log n) height.
 */
struct treap;

struct treap_kvpair;


/**
 * @brief       Create a new treap.
 * @param[in]   cmpfunc Compare function of the key data type.
 * @param[in]   ksize   Size in bytes of the key data type (used to allocate enough space for keys).
 *                      If \p ksize == 0, keys are not stored by value (not copied into the treap)
 *                      but stored by pointer instead.
 * @param[in]   vsize   Size in bytes of the value data type (used to allocate enough space for values).
 *                      If \p vsize == 0, values are not stored by value (not copied into the treap)
 *                      but stored by pointer instead.
 *                      If \p vsize < 0, values are not used at all, meaning the treap acts as set only, not as a map.
 * @return              A pointer to the newly created treap.
 */
extern struct treap* treap_create(treap_cmpfunc *cmpfunc, int ksize, int vsize);


/**
 * 
 */
extern struct treap treap_duplicate(const struct treap *self);


/**
 * @brief   Destroy a treap.
 * @details Free all memory associated with a treap.
 * @param[in] self The treap to the destroyed.
 */
extern void treap_destroy(struct treap *self);


/**
 *
 */
extern int treap_count(const struct treap *self);


/**
 * 
 */
extern int treap_datasize(const struct treap *self);


/**
 * @brief Insert a new key into a treap.
 * @param[in] self  The treap to be updated.
 * @param[in] key   Pointer to the key that is inserted.
 * @param[in] val   Pointer to the value that is inserted.
 */
extern void treap_insert(struct treap *self, const void *key, const void *val);


/**
 * @brief Remove a key from a treap.
 * @param[in] self  The treap to be updated.
 * @param[in] key   Pointer to the key that is to be remvoed.
 * @return          1 if \p key was removed, and 0 if \p key was not found.
 */
extern int treap_remove(struct treap *self, const void *key);


/**
 * 
 */
extern const struct treap_kvpair* treap_lookup(const struct treap *self, const void *key);


/**
 * 
 */
extern void treap_union(struct treap *self, const struct treap *other);


/**
 * 
 */
extern void treap_intersection(struct treap *self, const struct treap *other);


/**
 * 
 */
extern void treap_difference(struct treap *self, const struct treap *other);


/**
 * 
 */
extern void treap_foreach(const struct treap *self, treap_foreachfunc *func);


/**
 * 
 */
extern void treap_map(struct treap *self, treap_mapfunc *func);


/**
 * 
 */
extern void treap_toarray(const struct treap *self, void **buf, int *len);



#endif /* TREAP_H */
