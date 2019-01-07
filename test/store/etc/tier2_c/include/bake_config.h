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

#ifndef TIER1_TIER2_C_BAKE_CONFIG_H
#define TIER1_TIER2_C_BAKE_CONFIG_H

/* Headers of public dependencies */
#include <tier1>
#include <corto>
#include <tier1.c>
#include <corto.c>
#include <bake.util>

/* Headers of private dependencies */
#ifdef TIER1_TIER2_C_IMPL
/* No dependencies */
#endif

/* Convenience macro for exporting symbols */
#if TIER1_TIER2_C_IMPL && defined _MSC_VER
#define TIER1_TIER2_C_EXPORT __declspec(dllexport)
#elif TIER1_TIER2_C_IMPL
#define TIER1_TIER2_C_EXPORT __attribute__((__visibility__("default")))
#elif defined _MSC_VER
#define TIER1_TIER2_C_EXPORT __declspec(dllimport)
#else
#define TIER1_TIER2_C_EXPORT
#endif

#endif

