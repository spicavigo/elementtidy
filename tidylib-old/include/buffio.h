#ifndef __BUFFIO_H__
#define __BUFFIO_H__

/** @file buffio.h - Treat buffer as an I/O stream.

  (c) 1998-2003 (W3C) MIT, ERCIM, Keio University
  See tidy.h for the copyright notice.

  CVS Info :

    $LastChangedBy$ 
    $LastChangedDate$ 
    $LastChangedRevision$ 

  Requires buffer to automatically grow as bytes are added.
  Must keep track of current read and write points.

*/

#include "platform.h"
#include "tidy.h"

#ifdef __cplusplus
extern "C" {
#endif

/** TidyBuffer - A chunk of memory */
TIDY_STRUCT
struct _TidyBuffer 
{
    byte* bp;           /**< Pointer to bytes */
    uint  size;         /**< # bytes currently in use */
    uint  allocated;    /**< # bytes allocated */ 
    uint  next;         /**< Offset of current input position */
};

/** Zero out data structure */
TIDY_EXPORT void tidyBufInit( TidyBuffer* buf );

/** Free current buffer, allocate given amount, reset input pointer */
TIDY_EXPORT void tidyBufAlloc( TidyBuffer* buf, uint allocSize );

/** Expand buffer to given size. 
**  Chunk size is minimum growth. Pass 0 for default of 256 bytes.
*/
TIDY_EXPORT void tidyBufCheckAlloc( TidyBuffer* buf,
                                    uint allocSize, uint chunkSize );

/** Free current contents and zero out */
TIDY_EXPORT void tidyBufFree( TidyBuffer* buf );

/** Set buffer bytes to 0 */
TIDY_EXPORT void tidyBufClear( TidyBuffer* buf );

/** Attach to existing buffer */
TIDY_EXPORT void tidyBufAttach( TidyBuffer* buf, void* bp, uint size );

/** Detach from buffer.  Caller must free. */
TIDY_EXPORT void tidyBufDetach( TidyBuffer* buf );


/** Append bytes to buffer.  Expand if necessary. */
TIDY_EXPORT void tidyBufAppend( TidyBuffer* buf, void* vp, uint size );

/** Append one byte to buffer.  Expand if necessary. */
TIDY_EXPORT void tidyBufPutByte( TidyBuffer* buf, byte bv );

/** Get byte from end of buffer */
TIDY_EXPORT int  tidyBufPopByte( TidyBuffer* buf );


/** Get byte from front of buffer.  Increment input offset. */
TIDY_EXPORT int  tidyBufGetByte( TidyBuffer* buf );

/** At end of buffer? */
TIDY_EXPORT Bool tidyBufEndOfInput( TidyBuffer* buf );

/** Put a byte back into the buffer.  Decrement input offset. */
TIDY_EXPORT void tidyBufUngetByte( TidyBuffer* buf, byte bv );


/**************
   TIDY
**************/

/* Forward declarations
*/

/** Initialize a buffer input source */
TIDY_EXPORT void initInputBuffer( TidyInputSource* inp, TidyBuffer* buf );

/** Initialize a buffer output sink */
TIDY_EXPORT void initOutputBuffer( TidyOutputSink* outp, TidyBuffer* buf );

#ifdef __cplusplus
}
#endif
#endif /* __BUFFIO_H__ */
