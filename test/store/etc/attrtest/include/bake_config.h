/*
                                   )
                                  (.)
                                  .|.
                                  | |
                              _.--| |--._
                           .-';  ;`-'& ; `&.
                          \   &  ;    &   &_/
                           |"""---...---"""|
                           \ | | | | | | | /
                            `---.|.|.|.---'

 * This file is generated by bake.lang.c for your convenience. Headers of
 * dependencies will automatically show up in this file. Include bake_config.h
 * in your main project file. Do not edit! */

#ifndef ATTRTEST_BAKE_CONFIG_H
#define ATTRTEST_BAKE_CONFIG_H

/* Headers of public dependencies */
#include <corto>
#include <corto.c>
#include <bake.util>

/* Headers of private dependencies */
#ifdef ATTRTEST_IMPL
/* No dependencies */
#endif

/* Convenience macro for exporting symbols */
#if ATTRTEST_IMPL && defined _MSC_VER
#define ATTRTEST_EXPORT __declspec(dllexport)
#elif ATTRTEST_IMPL
#define ATTRTEST_EXPORT __attribute__((__visibility__("default")))
#elif defined _MSC_VER
#define ATTRTEST_EXPORT __declspec(dllimport)
#else
#define ATTRTEST_EXPORT
#endif

#endif
