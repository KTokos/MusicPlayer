#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>

using namespace std;

// time struct that contains the length of the song
struct songLength
{
	string minutes;
	string seconds;
};

// Music struct contains all variables for each song
struct music
{
	// Variables
	string song;
	string album;
	string artist;
	string genre;

	string played;

	songLength time;

	// Overloaded print operator
	friend ostream& operator<<(ostream& os, music song)
	{
		os << "Song: " << song.song << endl;
		os << "Album: " << song.album << endl;
		os << "Artist: " << song.artist << endl;
		os << "Genre: " << song.genre << endl;
		os << "Length of " << song.song << ": " << song.time.minutes << ":" << song.time.seconds << endl;
		os << "Times song played: " << song.played << endl;

		return os;
	}
};

// dbl_node struct for doubly linked list
struct dbl_node
{
	music song;
	dbl_node* prev = nullptr;
	dbl_node* next = nullptr;
};

// Declare class for doublyLinked List
class doublyLinkedList
{
private:
	dbl_node* dbl_head;
	dbl_node* dbl_tail;

public:
	//Constructor
	doublyLinkedList()
	{
		dbl_head = nullptr;
		dbl_tail = nullptr;
	}

	// Insert at beginning of a DLL
	void insertDouble(music newSong)
	{
		dbl_node* temp = new dbl_node;
		if (dbl_head == nullptr)
		{
			temp->song = newSong;
			temp->next = nullptr;
			temp->prev = nullptr;
			dbl_head = temp; // Update the front of the list
			dbl_tail = temp;
		}
		else
		{
			temp->song = newSong;
			temp->next = dbl_head; // Point to the front of the list
			temp->prev = nullptr;
			dbl_head->prev = temp;
			dbl_head = temp; // Update the front of the list
		}
	}

	// Insert at the end of a DLL with tail
	void insertEndDouble(music newSong)
	{
		dbl_node* temp = new dbl_node;
		temp->song = newSong;
		temp->next = nullptr;
		dbl_tail->next = temp;
		temp->prev = dbl_tail;
		dbl_tail = temp;
	}

	// Print the DLL
	void displayDouble()
	{
		int tempNum;
		tempNum = 1;

		cout << "The list: " << endl;
		dbl_node* temp = dbl_head;
		while (temp != nullptr)
		{
			cout << "Song " << tempNum << ":" << endl;
			cout << temp->song;
			cout << endl;
			temp = temp->next;
			tempNum++;
		}
		cout << endl;
	}

	void load(string playlistName)
	{
		// Dummy variable
		string dumb;

		// Load the file
		ifstream file(playlistName);

		if (file)
		{
			// File exists

			// Skip the first line of the input file
			//file.ignore(100, '\n');

			// Skip the first line of the input file
			getline(file, dumb);
			//cout << dumb << endl;
			// Read data from file
			while (file)
			{
				// Create temp struct
				music tempSong;

				// Get the song name from the input file
				getline(file, tempSong.song, ',');

				// Get the album name from the input file
				getline(file, tempSong.album, ',');

				// Get the artist name from the input file
				getline(file, tempSong.artist, ',');

				// Get the song length from the input file
				getline(file, tempSong.time.minutes, ':');
				getline(file, tempSong.time.seconds, ',');

				// Get the song genre from the input file
				getline(file, tempSong.genre, ',');

				// Get the times played from the input file
				getline(file, tempSong.played);					// Automatically skips to next song in file due to no delimeter

				// Insert the song into the list
				insertDouble(tempSong);
			}
		}
		else
		{
			// File does not exist

			cout << "File does not exist" << endl;
		}
	}

	// Uses an insertion sort to sort via song name
	void songSort()
	{
		if (!dbl_head || !dbl_head->next)
		{
			return;		// List is empty or has only one element
		}

		dbl_node* current = dbl_head->next;		// Start from the second node

		while (current)
		{
			dbl_node* key = current;			// The node to be inserted
			dbl_node* prevNode = current->prev;

			// Move key to its correct position in the sorted part of the list
			while (prevNode && prevNode->song.song > key->song.song)
			{
				//Swap the data between the nodes
				swap(prevNode->song, key->song);
				key = prevNode;
				prevNode = prevNode->prev;
			}

			current = current->next;	// Move to the next node to sort
		}
	}

	// Uses an insertion sort to sort via artist name
	void artistSort()
	{
		if (!dbl_head || !dbl_head->next)
		{
			return;		// List is empty or has only one element
		}

		dbl_node* current = dbl_head->next;		// Start from the second node

		while (current)
		{
			dbl_node* key = current;			// The node to be inserted
			dbl_node* prevNode = current->prev;

			// Move key to its correct position in the sorted part of the list
			while (prevNode && prevNode->song.artist > key->song.artist)
			{
				//Swap the data between the nodes
				swap(prevNode->song, key->song);
				key = prevNode;
				prevNode = prevNode->prev;
			}

			current = current->next;	// Move to the next node to sort
		}
	}

	// Displays the songs based on users choice of sort
	void Display()
	{
		// Declare temp variables
		int userChoice;

		// Prompt the user for how they want the songs displayed
		cout << endl << "Songs displayed by: " << endl;
		cout << "1) Song Title" << endl;
		cout << "2) Song Artist" << endl << endl;
		cout << "Choose here: ";
		cin >> userChoice;
		cout << endl;

		if (userChoice == 1)
		{
			// Sort by song
			songSort();

			//Display the list
			displayDouble();
		}
		else if (userChoice == 2)
		{
			// Sort by artist
			artistSort();

			//Display the list
			displayDouble();
		}
		else
		{
			// Invalid input
			cout << "Wrong choice idiot" << endl;
		}
	}

	bool checkForSong(music newSong)
	{
		dbl_node* temp = dbl_head;
		while (temp != nullptr)
		{
			// If the song is the same check the artist and album
			if (temp->song.song == newSong.song)
			{
				if (temp->song.artist == newSong.artist && temp->song.album == newSong.album)
				{
					return true;
				}
			}

			temp = temp->next;
		}

		return false;
	}

	// Adds a new song inputted by the user to the front of the playlist
	void Add()
	{
		// Declare a new song
		music newSong;

		//Song, Album, Artist, Song Length, Genre, Played
		// Prompt the user for data pertaining the new song
		cout << "Song name: ";
		cin >> newSong.song;
		cout << endl;

		cout << "Song album: ";
		cin >> newSong.album;
		cout << endl;

		cout << "Song artist: ";
		cin >> newSong.artist;
		cout << endl;

		cout << "Song length: ";
		getline(cin, newSong.time.minutes, ':');
		getline(cin, newSong.time.seconds, '\n');
		cout << endl;

		cout << "Song genre: ";
		cin >> newSong.genre;
		cout << endl;

		cout << "How many times played: ";
		cin >> newSong.played;
		cout << endl;

		// Checks if song is already in playlist, doesn't add it if function returns true
		if (checkForSong(newSong))
		{
			return;
		}
		else
		{
			// Add the song to the list
			insertDouble(newSong);
		}
		
	}
	
	// Deletes a song of the users choice via number listing
	void Delete()
	{
		// Declare needed variables
		int song;

		// Prompt the user for a song to delete
		cout << "Please input the number of the song you would like to delete: ";
		cin >> song;

		// Declare a temp node
		dbl_node* temp = dbl_head;
		
		// Declare a prev node
		dbl_node* previous = nullptr;

		if (song == 1)
		{
			// Chosen song is the head of the list
			dbl_head = temp->next;
			dbl_head->prev = nullptr;

			delete temp;
		}
		else
		{
			// Loop through the list to get to the song
			for (int i = 0; i < song - 1; i++)
			{
				previous = temp;
				temp = temp->next;
			}

			cout << "I'm fine" << endl;

			if (temp->next == nullptr)
			{
				cout << "Tail" << endl;

				previous->next = nullptr;

				delete temp;
			}
			else 
			{
				cout << "else" << endl;

				previous->next = temp->next;

				temp->next->prev = previous;

				//// Set the next of the previous node to the next from temp
				//temp->prev->next = temp->next;

				//// Set the prev of the next node to the prev from temp
				//temp->next->prev = temp->prev;

				// Delete temp
				delete temp;
			}
			

			
		}
	}

	// Prompts for the artists name and creates a new list of songs by just that artist
	doublyLinkedList FilterByArtist(doublyLinkedList artistPlaylist)
	{
		string artist;

		cout << "What artist would you like to listen to: ";
		cin >> artist;
		cout << endl;

		dbl_node* temp = dbl_head;
		while (temp != nullptr)
		{
			if (temp->song.artist == artist)
			{
				artistPlaylist.insertDouble(temp->song);
			}

			temp = temp->next;
		}

		return artistPlaylist;
	}

	// Prompts for genre and creates a list of songs containing that genre
	doublyLinkedList FilterByGenre(doublyLinkedList genrePlaylist)
	{
		string genre;

		cout << "What genre would you like to listen to: ";
		cin >> genre;
		cout << endl;

		dbl_node* temp = dbl_head;
		while (temp != nullptr)
		{
			if (temp->song.genre == genre)
			{
				genrePlaylist.insertDouble(temp->song);
			}

			temp = temp->next;
		}

		return genrePlaylist;
	}

	// Plays songs and adds them to a seperate list titled "recently played" that is saved upon exit
	// Can be recalled as one of the playlists. Play must prompt for the song to start playing from and plays until the end of the list
	doublyLinkedList Play(doublyLinkedList playedSongs)
	{
		string name;
		bool songReached;
		songReached = false;
		
		cout << "Where would you like to start listening (song name): ";
		cin >> name;

		dbl_node* temp = dbl_head;
		while (temp != nullptr)
		{
			if (temp->song.song == name)
			{
				songReached = true;
			}
			if (songReached)
			{
				// Output the song
				cout << "Currently playing: " << temp->song.song << " by " << temp->song.artist << endl;

				Sleep(3000);

				playedSongs.insertDouble(temp->song);
			}

			temp = temp->next;
		}

		return playedSongs;
	}

	// Will play songs at random throughout the list until all songs have been played
	// Needs to know which songs have been played so they are not played a second time
	doublyLinkedList Shuffle(doublyLinkedList shuffledSongs)
	{
		int chance;
		chance = 1;

		bool isIn;
		isIn = false;

		dbl_node* temp = dbl_head;
		while (temp != nullptr)
		{
			// Only runs when chance is even
			if (chance % 2 == 0)
			{
				shuffledSongs.insertDouble(temp->song);
			}

			chance++;

			temp = temp->next;
		}

		// Reset
		temp = dbl_head;

		// Create a temp to compare to
		dbl_node* shuffledTemp = shuffledSongs.dbl_head;

		while (temp != nullptr)
		{
			while (shuffledTemp != nullptr)
			{
				if (temp->song.song == shuffledTemp->song.song)
				{
					isIn = true;
				}

				shuffledTemp = shuffledTemp->next;
			}

			if (isIn != true)
			{
				shuffledSongs.insertDouble(temp->song);
			}

			// Reset
			shuffledTemp = shuffledSongs.dbl_head;
			temp = temp->next;
			isIn = false;
		}

		return shuffledSongs;
	}

	// Will append the recently played list and write the current playlist to a file
	// If the playlist is the result of a filter, must prompt for the name of the file
	// to save as
	void Store(doublyLinkedList list, string fileName)
	{
		ofstream outFile(fileName);

		if (outFile.is_open())
		{
			// Write the header
			outFile << "Song,Album,Artist,Song Length,Genre,Played";

			// --- Write the data ---
			dbl_node* temp = list.dbl_head;

			while (temp != nullptr)
			{
				outFile << "\n" << temp->song.song
					<< "," << temp->song.album
					<< "," << temp->song.artist
					<< "," << temp->song.time.minutes << ":" << temp->song.time.seconds
					<< "," << temp->song.genre
					<< "," << temp->song.played;

				temp = temp->next;
			}

			// Close the file
			outFile.close();
		}
	}
};
