#include "flow_server.h"
#include "flow_loop.h"

#include <stdio.h>
#include <stdlib.h>

namespace flow {

typedef struct {
  uv_write_t req;
  uv_buf_t buf;
} write_req_t;

void FlowServer::after_write(uv_write_t* req, int status) {
  write_req_t* wr;

  /* Free the read/write buffer and the request */
  wr = (write_req_t*) req;
  free(wr->buf.base);
  free(wr);

  if (status == 0)
    return;

  fprintf(stderr,
          "uv_write error: %s - %s\n",
          uv_err_name(status),
          uv_strerror(status));
}


void FlowServer::after_shutdown(uv_shutdown_t* req, int status) {
  uv_close((uv_handle_t*) req->handle, on_close);
  free(req);
}


void FlowServer::after_read(uv_stream_t* handle,
                       ssize_t nread,
                       const uv_buf_t* buf) {
  write_req_t *wr;
  uv_shutdown_t* sreq;

  if (nread < 0) {
    /* Error or EOF */
    ASSERT(nread == UV_EOF);

    free(buf->base);
    sreq = (uv_shutdown_t*)malloc(sizeof* sreq);
    ASSERT(0 == uv_shutdown(sreq, handle, after_shutdown));
    return;
  }

  if (nread == 0) {
    /* Everything OK, but nothing read. */
    free(buf->base);
    return;
  }

  // /*
  //  * Scan for the letter Q which signals that we should quit the server.
  //  * If we get QS it means close the stream.
  //  */
  // if (!server_closed) {
  //   for (i = 0; i < nread; i++) {
  //     if (buf->base[i] == 'Q') {
  //       if (i + 1 < nread && buf->base[i + 1] == 'S') {
  //         free(buf->base);
  //         uv_close((uv_handle_t*)handle, on_close);
  //         return;
  //       } else {
  //         uv_close(server, on_server_close);
  //         server_closed = 1;
  //       }
  //     }
  //   }
  // }

  wr = (write_req_t*) malloc(sizeof *wr);
  ASSERT(wr != NULL);
  wr->buf = uv_buf_init(buf->base, nread);
  
  if (uv_write(&wr->req, handle, &wr->buf, 1, after_write)) {
      printf("uv_write failed");
  }
}


void FlowServer::on_close(uv_handle_t* peer) {
  free(peer);
}

void FlowServer::on_server_close(uv_handle_t* handle) {
  free(handle);
}

void FlowServer::echo_alloc(uv_handle_t* handle,
	                       size_t suggested_size,
	                       uv_buf_t* buf) {
  buf->base = (char*)malloc(suggested_size * sizeof(char));
  buf->len = suggested_size;
}


void FlowServer::on_connection(uv_stream_t* server, int status) {
  LoopPtr loop = ((FlowServer*)server->data)->GetLoop();

  uv_stream_t* stream;
  
  if (status != 0) {
    fprintf(stderr, "Connect error %s\n", uv_err_name(status));
  }
  ASSERT(status == 0);

 
  stream = (uv_stream_t*)malloc(sizeof(uv_tcp_t));
  ASSERT(stream != NULL);
  int r = uv_tcp_init(loop->self(), (uv_tcp_t*)stream);
  ASSERT(r == 0);
  
   r = uv_accept(server, stream);
   ASSERT(r == 0);

   r = uv_read_start(stream, echo_alloc, after_read);
   ASSERT(r == 0);
}

FlowServer::FlowServer(LoopPtr loop) : loop_(loop) {
  int r = uv_tcp_init(loop_->self(), &tcpServer_);
  server_closed_ = 0;
  if (r) {
    /* TODO: Error codes */
    fprintf(stderr, "Socket creation error\n");
  }
}

FlowServer::~FlowServer() {
   
}

int FlowServer::Bind(const struct sockaddr_in* addr, unsigned int flags) {
   int r = uv_tcp_bind(&tcpServer_, (const struct sockaddr*) addr, flags);
   if (r) {
	    /* TODO: Error codes */
	    fprintf(stderr, "Bind error\n");
	    return 1;
   }
   return r;
}

int FlowServer::Listen(int blacklog) {
   tcpServer_.data = this;
   int r = uv_listen((uv_stream_t*)&tcpServer_, blacklog, on_connection);
   if (r) {
     /* TODO: Error codes */
     fprintf(stderr, "Listen error %s\n", uv_err_name(r));
     return 1;
   }
   return r;
}

LoopPtr FlowServer::GetLoop() {
  return loop_;
}
}