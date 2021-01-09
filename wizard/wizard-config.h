/*
  Copyright 1999-2021 ImageMagick Studio LLC, a non-profit organization
  dedicated to making software imaging solutions freely available.

  You may not use this file except in compliance with the License.  You may
  obtain a copy of the License at

    https://imagemagick.org/script/license.php

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  MagickConfig not autogenerated (fixed stuff)
*/
#ifndef WIZARDSTOOLKIT_MAGICK_CONFIG_H
#define WIZARDSTOOLKIT_MAGICK_CONFIG_H

#if defined(__cplusplus) || defined(c_plusplus)
extern "C" {
#endif

#include "wizard/wizard-baseconfig.h"

#define WIZARDSTOOLKIT_STRING_QUOTE(str) #str
#define WIZARDSTOOLKIT_STRING_XQUOTE(str) WIZARDSTOOLKIT_STRING_QUOTE(str)

#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
# if defined(__GNUC__) || defined(__clang__)
#  define MAGICK_COMPILER_WARNING(w) _Pragma(WIZARDSTOOLKIT_STRING_QUOTE(GCC warning w))
# elif defined(_MSC_VER)
#  define MAGICK_COMPILER_WARNING(w) _Pragma(WIZARDSTOOLKIT_STRING_QUOTE(message(w)))
# endif
#endif

#ifndef MAGICK_COMPILER_WARNING
# define MAGICK_COMPILER_WARNING(w)
#endif

#ifdef WIZARDSTOOLKIT__FILE_OFFSET_BITS
# ifdef _FILE_OFFSET_BITS
#  if _FILE_OFFSET_BITS != WIZARDSTOOLKIT__FILE_OFFSET_BITS
    MAGICK_COMPILER_WARNING("_FILE_OFFSET_BITS is already defined, but does not match WIZARDSTOOLKIT__FILE_OFFSET_BITS")
#  else
#   undef _FILE_OFFSET_BITS
#  endif
# endif
# ifndef _FILE_OFFSET_BITS
#  if WIZARDSTOOLKIT__FILE_OFFSET_BITS == 64
#   define _FILE_OFFSET_BITS 64
#  elif WIZARDSTOOLKIT__FILE_OFFSET_BITS == 32
#   define _FILE_OFFSET_BITS 32
#  else
#   define _FILE_OFFSET_BITS WIZARDSTOOLKIT__FILE_OFFSET_BITS
#  endif
# endif
#endif

/* Compatibility block */
#if !defined(WIZARDSTOOLKIT_QUANTUM_DEPTH) && defined(WIZARDSTOOLKIT_QUANTUM_DEPTH_OBSOLETE_IN_H)
# warning "you should set WIZARDSTOOLKIT_QUANTUM_DEPTH to sensible default set it to configure time default"
# warning "this is an obsolete behavior please fix your makefile"
# define WIZARDSTOOLKIT_QUANTUM_DEPTH WIZARDSTOOLKIT_QUANTUM_DEPTH_OBSOLETE_IN_H
#endif

#if defined __CYGWIN32__ && !defined __CYGWIN__
   /* For backwards compatibility with Cygwin b19 and
      earlier, we define __CYGWIN__ here, so that
      we can rely on checking just for that macro. */
#  define __CYGWIN__  __CYGWIN32__
#endif

/*  ABI SUFFIX */
#ifndef WIZARDSTOOLKIT_HDRI_SUPPORT
#define WIZARDSTOOLKIT_ABI_SUFFIX  "Q" WIZARDSTOOLKIT_STRING_XQUOTE(WIZARDSTOOLKIT_QUANTUM_DEPTH)
#else 
#define WIZARDSTOOLKIT_ABI_SUFFIX "Q" WIZARDSTOOLKIT_STRING_XQUOTE(WIZARDSTOOLKIT_QUANTUM_DEPTH) "HDRI"
#endif 

/* some path game */
#if !defined __CYGWIN__
# if defined (_WIN32) || defined (_WIN64) || defined (__MSDOS__) || defined (__DJGPP__) || defined (__OS2__)
   /* Use Windows separators on all _WIN32 defining
      environments, except Cygwin. */
#  define WIZARDSTOOLKIT_DIR_SEPARATOR_CHAR		'\\'
#  define WIZARDSTOOLKIT_DIR_SEPARATOR		"\\"
#  define WIZARDSTOOLKIT_PATH_SEPARATOR_CHAR	';'
#  define WIZARDSTOOLKIT_PATH_SEPARATOR		";"
# endif
#endif
 
/* posix */
#ifndef WIZARDSTOOLKIT_DIR_SEPARATOR_CHAR
   /* Assume that not having this is an indicator that all
      are missing. */
#  define WIZARDSTOOLKIT_DIR_SEPARATOR_CHAR		'/'
#  define WIZARDSTOOLKIT_DIR_SEPARATOR		"/"
#  define WIZARDSTOOLKIT_PATH_SEPARATOR_CHAR	':'
#  define WIZARDSTOOLKIT_PATH_SEPARATOR		":"
#endif /* !DIR_SEPARATOR_CHAR */

# if defined(WIZARDSTOOLKIT_POSIX_SUPPORT) || defined(__MINGW32__)
 
/* module dir */
#ifndef WIZARDSTOOLKIT_MODULES_DIRNAME
# define WIZARDSTOOLKIT_MODULES_DIRNAME WIZARDSTOOLKIT_MODULES_BASEDIRNAME "-" WIZARDSTOOLKIT_ABI_SUFFIX
#endif
 
#ifndef WIZARDSTOOLKIT_MODULES_PATH
#  define WIZARDSTOOLKIT_MODULES_PATH WIZARDSTOOLKIT_LIBRARY_PATH WIZARDSTOOLKIT_DIR_SEPARATOR WIZARDSTOOLKIT_MODULES_DIRNAME
#endif
 
#ifndef WIZARDSTOOLKIT_MODULES_RELATIVE_PATH
#define WIZARDSTOOLKIT_MODULES_RELATIVE_PATH WIZARDSTOOLKIT_LIBRARY_RELATIVE_PATH WIZARDSTOOLKIT_DIR_SEPARATOR WIZARDSTOOLKIT_MODULES_DIRNAME
#endif
 
/* Subdirectory under lib to place ImageMagick coder module files */
#ifndef WIZARDSTOOLKIT_CODER_PATH
# if defined(vms)
#  define WIZARDSTOOLKIT_CODER_PATH "sys$login:"
# else
#  define WIZARDSTOOLKIT_CODER_PATH WIZARDSTOOLKIT_MODULES_PATH WIZARDSTOOLKIT_DIR_SEPARATOR WIZARDSTOOLKIT_CODER_DIRNAME
# endif
#endif
 
#ifndef WIZARDSTOOLKIT_CODER_RELATIVE_PATH
# define WIZARDSTOOLKIT_CODER_RELATIVE_PATH WIZARDSTOOLKIT_MODULES_RELATIVE_PATH WIZARDSTOOLKIT_DIR_SEPARATOR WIZARDSTOOLKIT_CODER_DIRNAME
#endif
 
/* subdirectory under lib to place ImageMagick filter module files */
#ifndef WIZARDSTOOLKIT_FILTER_PATH
# if defined(vms)
#  define WIZARDSTOOLKIT_FILTER_PATH  "sys$login:"
# else
#  define WIZARDSTOOLKIT_FILTER_PATH WIZARDSTOOLKIT_MODULES_PATH WIZARDSTOOLKIT_DIR_SEPARATOR WIZARDSTOOLKIT_FILTER_DIRNAME
# endif
#endif
 
#ifndef WIZARDSTOOLKIT_FILTER_RELATIVE_PATH
# define WIZARDSTOOLKIT_FILTER_RELATIVE_PATH WIZARDSTOOLKIT_MODULES_RELATIVE_PATH WIZARDSTOOLKIT_DIR_SEPARATOR WIZARDSTOOLKIT_FILTER_DIRNAME
#endif

/* sharearch dir */
#ifndef WIZARDSTOOLKIT_SHAREARCH_DIRNAME
# define WIZARDSTOOLKIT_SHAREARCH_DIRNAME WIZARDSTOOLKIT_SHAREARCH_BASEDIRNAME "-" WIZARDSTOOLKIT_ABI_SUFFIX
#endif
 
#ifndef WIZARDSTOOLKIT_SHAREARCH_PATH
#  define WIZARDSTOOLKIT_SHAREARCH_PATH WIZARDSTOOLKIT_LIBRARY_PATH WIZARDSTOOLKIT_DIR_SEPARATOR WIZARDSTOOLKIT_SHAREARCH_DIRNAME WIZARDSTOOLKIT_DIR_SEPARATOR
#endif
 
#ifndef WIZARDSTOOLKIT_SHAREARCH_RELATIVE_PATH
#define WIZARDSTOOLKIT_SHAREARCH_RELATIVE_PATH WIZARDSTOOLKIT_LIBRARY_RELATIVE_PATH WIZARDSTOOLKIT_DIR_SEPARATOR WIZARDSTOOLKIT_SHAREARCH_DIRNAME
#endif

#endif

/* for Clang compatibility */
#ifndef __has_builtin
#  define __has_builtin(x) 0
#endif

#if defined(__GNUC__) && !defined(__clang__)
# define WIZARDSTOOLKIT_DIAGNOSTIC_PUSH() \
   _Pragma("GCC diagnostic push")
# define WIZARDSTOOLKIT_DIAGNOSTIC_IGNORE_MAYBE_UNINITIALIZED() \
   _Pragma("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define WIZARDSTOOLKIT_DIAGNOSTIC_POP() \
   _Pragma("GCC diagnostic pop")
#else
# define WIZARDSTOOLKIT_DIAGNOSTIC_PUSH()
# define WIZARDSTOOLKIT_DIAGNOSTIC_IGNORE_MAYBE_UNINITIALIZED()
# define WIZARDSTOOLKIT_DIAGNOSTIC_POP()
#endif

#define WIZARDSTOOLKIT_BITS_BELOW(power_of_2) \
  ((power_of_2)-1)

#define WIZARDSTOOLKIT_MAX_ALIGNMENT_PADDING(power_of_2) \
  WIZARDSTOOLKIT_BITS_BELOW(power_of_2)

#define WIZARDSTOOLKIT_IS_NOT_ALIGNED(n, power_of_2) \
  ((n) & WIZARDSTOOLKIT_BITS_BELOW(power_of_2))

#define WIZARDSTOOLKIT_IS_NOT_POWER_OF_2(n) \
  WIZARDSTOOLKIT_IS_NOT_ALIGNED((n), (n))

#define WIZARDSTOOLKIT_ALIGN_DOWN(n, power_of_2) \
  ((n) & ~WIZARDSTOOLKIT_BITS_BELOW(power_of_2))

#define WIZARDSTOOLKIT_ALIGN_UP(n, power_of_2) \
  WIZARDSTOOLKIT_ALIGN_DOWN((n) + WIZARDSTOOLKIT_MAX_ALIGNMENT_PADDING(power_of_2),power_of_2)
 
#if defined(__cplusplus) || defined(c_plusplus)
}
#endif
 
#endif
