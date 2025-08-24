#ifndef NANOMQ_VCAS_H
#define NANOMQ_VCAS_H

#include "nng/nng.h"
#include "nng/supplemental/nanolib/conf.h"
#include "nng/supplemental/nanolib/mqtt_db.h"

typedef struct vcas_work {
	enum {
		VCAS_INIT,
		VCAS_RECV,
		VCAS_WAIT,
		VCAS_SEND,
	} state;

	conf *config;

	nng_aio  *aio;
	nng_msg  *msg;
	nng_msg **msg_ret;
	nng_ctx   ctx;
	nng_pipe  pid;

	dbtree *db;
	dbtree *db_ret;

	struct pipe_content *pipe_ct;
} vcas_work;

#endif // NANOMQ_VCAS_H
