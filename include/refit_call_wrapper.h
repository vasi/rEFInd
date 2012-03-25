#ifndef __REFIT_CALL_WRAPPER_H__
#define __REFIT_CALL_WRAPPER_H__

#ifdef EFIX64
# define refit_call1_wrapper(f, a1) \
  uefi_call_wrapper(f, 1, (UINT64)(a1))
# define refit_call2_wrapper(f, a1, a2) \
  uefi_call_wrapper(f, 2, (UINT64)(a1), (UINT64)(a2))
# define refit_call3_wrapper(f, a1, a2, a3) \
  uefi_call_wrapper(f, 3, (UINT64)(a1), (UINT64)(a2), (UINT64)(a3))
# define refit_call4_wrapper(f, a1, a2, a3, a4) \
  uefi_call_wrapper(f, 4, (UINT64)(a1), (UINT64)(a2), (UINT64)(a3), (UINT64)(a4))
# define refit_call5_wrapper(f, a1, a2, a3, a4, a5) \
  uefi_call_wrapper(f, 5, (UINT64)(a1), (UINT64)(a2), (UINT64)(a3), (UINT64)(a4), (UINT64)(a5))
# define refit_call6_wrapper(f, a1, a2, a3, a4, a5, a6) \
  uefi_call_wrapper(f, 6, (UINT64)(a1), (UINT64)(a2), (UINT64)(a3), (UINT64)(a4), (UINT64)(a5), (UINT64)(a6))
# define refit_call10_wrapper(f, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10) \
  uefi_call_wrapper(f, 10, (UINT64)(a1), (UINT64)(a2), (UINT64)(a3), (UINT64)(a4), (UINT64)(a5), (UINT64)(a6), (UINT64)(a7), (UINT64)(a8), (UINT64)(a9), (UINT64)(a10))
#else
# define refit_call1_wrapper(f, a1) \
  uefi_call_wrapper(f, 1, a1)
# define refit_call2_wrapper(f, a1, a2) \
  uefi_call_wrapper(f, 2, a1, a2)
# define refit_call3_wrapper(f, a1, a2, a3) \
  uefi_call_wrapper(f, 3, a1, a2, a3)
# define refit_call4_wrapper(f, a1, a2, a3, a4) \
  uefi_call_wrapper(f, 4, a1, a2, a3, a4)
# define refit_call5_wrapper(f, a1, a2, a3, a4, a5) \
  uefi_call_wrapper(f, 5, a1, a2, a3, a4, a5)
# define refit_call6_wrapper(f, a1, a2, a3, a4, a5, a6) \
  uefi_call_wrapper(f, 6, a1, a2, a3, a4, a5, a6)
# define refit_call10_wrapper(f, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10) \
  uefi_call_wrapper(f, 10, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10)
#endif

#endif /* !__REFIT_CALL_WRAPPER_H__ */

