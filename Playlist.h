/*************************************************************************
   This class is a container that holds objects of the class Song.
   It uses an internal iterator to give the application the ability to
   order the container as well as access to the elements in the container.
   Because it uses dynamic memory it needs to have the Big3.

	Patricia Lindner	Fall 2021		Ohio University EECS
*************************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include "Song.h"
#ifndef PLAYLIST_H
#define PLAYLIST_H

class Playlist{
    public:
        /**
         * @brief Construct a new Playlist object.
         */
        Playlist();


        // The Big 3

        /**
         * @brief Destroy the Playlist object.
         */
        ~Playlist();

        /**
         * @brief Construct a new Playlist object from an existing Playlist object.
         * 
         * @param other the exisiting Playlist object to copy values from
         */
        Playlist(const Playlist& other);

        /**
         * @brief Set the values of a Playlist object based on the values of an exisiting Playlist object.
         * 
         * @param other the exisiting Playlist object to copy values from
         */
        void operator = (const Playlist& other);


        // Functions for the internal iterator

        /**
         * @brief Set the interator to point to the first Song.
         */
        void start();

        /**
         * @brief Set the iterator to point to the next Song.
         */
        void advance();

        /**
         * @brief Returns true if the iterator is pointing to a used space in the Playlist.
         * 
         * @return true if the iterator is pointing to a used space in the Playlist
         */
        bool is_item()const;

        /**
         * @brief Returns the Song being pointed to by the interator.
         * 
         * @return the Song being pointed to by the iterator
         */
        Song current()const;


        // Other useful things the user may want to do

        /**
         * @brief Remove the Song pointed to by the iterator.
         */
        void remove_current();

        /**
         * @brief Inserts a Song before the Song pointed to by the iterator.
         * 
         * @param s the Song to be inserted
         */
        void insert(const Song& s);

        /**
         * @brief Attaches a Song after the Song pointed to by the iterator.
         * 
         * @param s the Song to be attached
         */
        void attach(const Song& s);


        /**
         * @brief Output all the Songs in the Playlist.
         * 
         * @param outs the ostream to output to
         */
        void show_all(std::ostream& outs)const;

        /**
         * @brief Sort the Songs by release date.
         */
        void releaseDate_sort();

        /**
         * @brief Sort the Songs by artist.
         */
        void artist_sort();

        /**
         * @brief Return the first Song that matches a given name.
         * 
         * @param name the name to check for
         * @return the Song that matches
         */
        Song find_song(const std::string& name)const;

        /**
         * @brief Check if a Song is valid.
         * 
         * @param s the Song to be checked
         * @return true if the Song is valid
         */
        bool is_song(const Song& s) const;

        /**
         * @brief Load a Playlist from an istream.
         * 
         * @param ins the istream to load the Playlist from
         */
        void load(std::istream& ins);

        /**
         * @brief Output a playlist to an ostream.
         * 
         * @param outs the ostream to output the Playlist to
         */
        void save(std::ostream& outs)const;

    private:
        Song *data;         // the array of Songs
        int used;           // the number of Songs held in the array
        int capacity;       // the maximum number of Songs to 
        int current_index;  // the iterator that points to a certain Song within the Playlist

        /**
         * @brief Increases the capacity of the container by 5.
         */
        void resize();
};

#endif