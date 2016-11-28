#ifndef SHARED_H
#define SHARED_H
/**
 * @file shared.h defines the data structures that need to be shared across all
 * files. This is mainly here so we can avoid recursive includes for commonly 
 * used structures
 **/
/**
 * definition of the BOOLEAN datatype
 **/
typedef enum
{
        /**
         * value for FALSE (0)
         **/
        FALSE,
        /** 
         * value for TRUE (1)
         **/
        TRUE
} BOOLEAN;
#endif
