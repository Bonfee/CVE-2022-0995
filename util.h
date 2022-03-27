#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <sched.h>
#include <pthread.h>
#include <poll.h>
#include <assert.h>
#include <time.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/wait.h>
#include <sys/syscall.h>
#include <sys/ioctl.h>
#include <linux/sched.h>

typedef struct {
  long mtype;
  char mtext[1];
} msg;

typedef struct {
  uint64_t m_list_next;
  uint64_t m_list_prev;
  uint64_t m_type;
  uint64_t m_ts;
  uint64_t next;
  uint64_t security;
} msg_msg;

struct pipe_buffer {
	uint64_t page;
	uint32_t offset, len;
	uint64_t ops;
	uint32_t flags;
	uint64_t prv;
};

struct pipe_buf_operations {
	uint64_t confirm;
	uint64_t release;
	uint64_t try_steal;
	uint64_t get;
};

int32_t make_queue(key_t key, int msgflg);
ssize_t get_msg(int msqid, void *msgp, size_t msgsz, long msgtyp, int msgflg);
ssize_t get_msg_no_err(int msqid, void *msgp, size_t msgsz, long msgtyp, int msgflg);
void send_msg(int msqid, void *msgp, size_t msgsz, int msgflg);