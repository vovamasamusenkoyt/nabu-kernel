#ifndef __KSU_H_KERNEL_UMOUNT
#define __KSU_H_KERNEL_UMOUNT

#include <linux/types.h>
#include <linux/list.h>
#include <linux/rwsem.h>

void ksu_kernel_umount_init(void);
void ksu_kernel_umount_exit(void);

// Handler function to be called from setresuid hook
int ksu_handle_umount(uid_t old_uid, uid_t new_uid);

#ifdef CONFIG_KSU_SUSFS
// called on EVENT_POST_FS_DATA to resolve susfs auto-hide feature flags
void susfs_on_post_fs_data(void);
#ifdef CONFIG_KSU_SUSFS_TRY_UMOUNT
void ksu_try_umount(const char *mnt, bool check_mnt, int flags, uid_t uid);
void susfs_try_umount_all(uid_t uid);
#endif
#endif

// for the umount list
struct mount_entry {
    char *umountable;
    unsigned int flags;
    struct list_head list;
};
extern struct list_head mount_list;
extern struct rw_semaphore mount_list_lock;

#endif
