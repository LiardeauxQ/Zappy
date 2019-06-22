/*
** EPITECH PROJECT, 2018
** Packet.hpp
** File description:
** Packet header
*/

#pragma once

#include <stdlib.h>

#include "protocols.h"

namespace communication {
    template <class T>
    class Packet {
    public:
        Packet(uint8_t id, int sockfd, uint16_t size = 0, uint16_t subid = 0)
            : id(id), sockfd(sockfd), size(size), subid(subid)
        {
        }

        ~Packet() = default;

        Packet<T> &operator<<(const T *data) //send
        {
            packet_header hdr = {id, PROTOCOL_VERSION, size, subid};

            write(sockfd, &hdr, sizeof(hdr));
            write(sockfd, data, sizeof(T));
            return (*this);
        }

        void operator>>(T *data) //receive
        {
            packet_header hdr = {0, 0, 0, 0};
            int result = 0;

            result = read(sockfd, &hdr, PKT_HDR_LEN);
            if (result != PKT_HDR_LEN || hdr.id > SRV_CUSTOM) {
                data = nullptr;
                return;
            }
            result = read(sockfd, data, hdr.size);
        }

    private:
        uint8_t id;
        int sockfd;
        uint16_t size;
        uint16_t subid;
    };
}
