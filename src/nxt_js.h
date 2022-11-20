
/*
 * Copyright (C) NGINX, Inc.
 */

#ifndef _NXT_JS_H_INCLUDED_
#define _NXT_JS_H_INCLUDED_

#if (NXT_HAVE_NJS)

#include <njs_main.h>


typedef struct nxt_js_s       nxt_js_t;
typedef struct nxt_js_conf_s  nxt_js_conf_t;


typedef struct {
    njs_vm_t            *vm;
    njs_value_t         array;
} nxt_js_cache_t;


nxt_js_conf_t *nxt_js_conf_new(nxt_mp_t *mp);
nxt_js_t *nxt_js_add_tpl(nxt_js_conf_t *jcf, nxt_str_t *str, nxt_bool_t strz);
nxt_int_t nxt_js_compile(nxt_js_conf_t *jcf);
nxt_int_t nxt_js_test(nxt_js_conf_t *jcf, nxt_str_t *str, u_char *error);
nxt_int_t nxt_js_call(nxt_task_t *task, nxt_js_cache_t *cache, nxt_js_t *js,
    nxt_str_t *str, void *ctx);


#endif /* NXT_HAVE_NJS */

#endif /* _NXT_JS_H_INCLUDED_ */
