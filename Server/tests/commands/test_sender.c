/*
** EPITECH PROJECT, 2018
** test_sender.c
** File description:
** test sender
*/

#include <criterion/criterion.h>

#include "graphical/commands.h"

Test(convert_senders_to_data, simple_test)
{
    sender_t *converted_sender = 0x0;
    sender_t senders[2] = {};
    void *data = 0;

    senders[0] = (sender_t){0x0, 987, 1, 0};
    senders[1] = (sender_t){0x0, 567, 1, 1};
    data = convert_senders_to_data(senders);
    cr_assert_eq(*(int*)data, SENDER_MAGIC_NUM);
    converted_sender = (sender_t*)(data + SENDER_MAGIC_NUM_LEN);
    cr_assert_eq(converted_sender->data, 0x0);
    cr_assert_eq(converted_sender->size, 987);
    cr_assert_eq(converted_sender->sockfd, 1);
    cr_assert_eq(converted_sender->is_last, 0);
    converted_sender = (sender_t*)(data + sizeof(sender_t)
            + SENDER_MAGIC_NUM_LEN);
    cr_assert_eq(converted_sender->data, 0x0);
    cr_assert_eq(converted_sender->size, 567);
    cr_assert_eq(converted_sender->sockfd, 1);
    cr_assert_eq(converted_sender->is_last, 1);
    free(data);
}

Test(convert_senders_to_data, null_parameter)
{
    void *data = convert_senders_to_data(0x0);

    cr_assert_eq(data, 0x0);
}

Test(get_senders_from_data, simple_test)
{
    char data[] = {118, 25, 4, 1,
                  0, 0, 0, 0, 0, 0, 0, 0,
                  34, 0, 0, 0, 0, 0, 0, 0,
                  3, 0, 0, 0, 0, 0, 0, 0,
                  0, 0, 0, 0, 0, 0, 0, 0,
                  66, 0, 0, 0, 0, 0, 0, 0,
                  10, 0, 0, 0, 1, 0, 0, 0};
    sender_t *senders = get_senders_from_data(data);

    cr_assert_eq(senders[0].data, 0);
    cr_assert_eq(senders[0].size, 34);
    cr_assert_eq(senders[0].sockfd, 3);
    cr_assert_eq(senders[0].is_last, 0);
}
