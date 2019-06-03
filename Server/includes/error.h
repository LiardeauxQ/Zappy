/*
** EPITECH PROJECT, 2018
** error.h
** File description:
** handle errors
*/

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <sys/errno.h>

#define EXIT_ERROR 84

void exit_with_error(char const *msg);
int print_exit_msg(char const *msg, int exit_value);
