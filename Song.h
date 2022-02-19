/*************************************************************************
   This is the header file for a class called Song. It holds the 
   information about a single song, the name, release date, and artist. 
   It uses a class called Date for the storage of the release date. 
   The member functions are just accessors and input/output functions.

	   Patricia Lindner	    Spring 2022		Ohio University
*************************************************************************/

#include <iostream>
#include <string>
#include "date.h"
#ifndef SONG_H
#define SONG_H

class Song{
    public:
		/**
		 * @brief Construct a new Song object.
		 */
		Song();

		/**
		 * @brief Get the name of the Song.
		 * 
		 * @return the name of the Song
		 */
		std::string get_name()const;

		/**
		 * @brief Get the release date of the Song.
		 * 
		 * @return the release date of the Song
		 */
		Date get_release()const;

		/**
		 * @brief Get the artist of the Song.
		 * 
		 * @return the artist of the Song
		 */
        std::string get_artist()const;


		/**
		 * @brief Compare the Song object to another one.
		 * 
		 * @param other the other Song
		 * @return true if the Songs contain the same data
		 */
		bool operator == (const Song& other)const;

		/**
		 * @brief Compare the Song object to another one.
		 * 
		 * @param other the other Song
		 * @return true if the Songs don't contain the same data
		 */
		bool operator != (const Song& other)const;


		/**
		 * @brief Set the Song data based on input from an istream.
		 * 
		 * @param ins the istream to get the data from
		 */
		void input(std::istream& ins);

		/**
		 * @brief Output the Song data to an ostream.
		 * 
		 * @param outs the ostream to output the data to
		 */
		void output(std::ostream& outs)const;

    private:
		std::string name;    // the name of the Song
		Date release;        // the release date of the Song
        std::string artist;  // the artist of the Song
};

/**
 * @brief Set the Song data based on input from an istream.
 * 
 * @param ins the istream to get the data from
 */
std::istream& operator >> (std::istream& ins, Song& s);

/**
 * @brief Output the Song data to an ostream.
 * 
 * @param outs the ostream to output the data to
 */
std::ostream& operator << (std::ostream& outs, const Song& s);

#endif