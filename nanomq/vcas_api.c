#include "vcas.h"

int
vcas_listen(nng_socket sid, const char *addr, nng_listener *lp, int flags,
    conf *config)
{
	int          rv;
	nng_listener l;

	nng_listener_create(&l, sid, addr);

	if ((rv = nng_listener_start(l, 0)) != 0) {
		nng_listener_close(l);
		return rv;
	}

	if (lp != NULL) {
		nng_listener lid;
		lid.id = nng_listener_id(l);
		*lp    = lid;
	}

	return rv;
}
