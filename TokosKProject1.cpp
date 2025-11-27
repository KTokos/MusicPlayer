#include <iostream>
#include <string>
#include "doublyLinkedList.h"

using namespace std;

int main(void)
{
	int userChoice;

	bool unlocked = true;
	doublyLinkedList playlist;

	bool unlockedArtist = false;
	doublyLinkedList artistPlaylist;

	bool unlockedGenre = false;
	doublyLinkedList genrePlaylist;

	bool unlockedPlayed = false;
	doublyLinkedList playedSongs;

	bool unlockedShuffled = false;
	doublyLinkedList shuffledSongs;

	playlist.load("playlist.csv");

	while (unlocked)
	{
		// Reset userChoice
		userChoice = 0;

		cout << "Please choose what you would like to do:" << endl;
		cout << "1) Display the songs" << endl;
		cout << "2) Add a new song" << endl;
		cout << "3) Delete a song" << endl;
		cout << "4) Filter by Artist" << endl;
		cout << "5) Filter by Genre" << endl;
		cout << "6) Play a playlist" << endl;
		cout << "7) Shuffle" << endl;
		cout << "8) Store a playlist" << endl;
		cout << "9) Exit" << endl;

		cout << endl << "Choose here: ";
		cin >> userChoice;
		cout << endl;

		// Display the songs
		if (userChoice == 1)
		{
			// Reset userChoice
			userChoice = 0;

			cout << "Which playlist would you like to display: " << endl;
			cout << "1) Default Playlist" << endl;
			
			if (unlockedArtist)
			{
				cout << "2) Artist Playlist" << endl;
			}
			if (unlockedGenre)
			{
				cout << "3) Genre Playlist" << endl;
			}
			if (unlockedPlayed)
			{
				cout << "4) Recently Played" << endl;
			}
			if (unlockedShuffled)
			{
				cout << "5) Shuffled Playlist" << endl;
			}

			cin >> userChoice;

			switch (userChoice)
			{
			case 1:
				playlist.Display();

				break;
			case 2:
				artistPlaylist.Display();

				break;
			case 3:
				genrePlaylist.Display();

				break;
			case 4:
				playedSongs.Display();

				break;
			case 5:
				shuffledSongs.Display();

				break;
			}
		}
		// Add a new song
		else if (userChoice == 2)
		{
			// Reset userChoice
			userChoice = 0;

			cout << "Which playlist would you like to add to: " << endl;
			cout << "1) Default Playlist" << endl;

			if (unlockedArtist)
			{
				cout << "2) Artist Playlist" << endl;
			}
			if (unlockedGenre)
			{
				cout << "3) Genre Playlist" << endl;
			}
			if (unlockedPlayed)
			{
				cout << "4) Recently Played" << endl;
			}
			if (unlockedShuffled)
			{
				cout << "5) Shuffled Playlist" << endl;
			}

			cin >> userChoice;

			switch (userChoice)
			{
			case 1:
				playlist.Add();

				break;
			case 2:
				artistPlaylist.Add();

				break;
			case 3:
				genrePlaylist.Add();

				break;
			case 4:
				playedSongs.Add();

				break;
			case 5:
				shuffledSongs.Add();

				break;
			}
		}
		// Delete a song
		else if (userChoice == 3)
		{
			// Reset userChoice
			userChoice = 0;

			cout << "Which playlist would you like to delete from: " << endl;
			cout << "1) Default Playlist" << endl;
			
			if (unlockedArtist)
			{
				cout << "2) Artist Playlist" << endl;
			}
			if (unlockedGenre)
			{
				cout << "3) Genre Playlist" << endl;
			}
			if (unlockedPlayed)
			{
				cout << "4) Recently Played" << endl;
			}
			if (unlockedShuffled)
			{
				cout << "5) Shuffled Playlist" << endl;
			}

			cin >> userChoice;

			switch (userChoice)
			{
			case 1:
				playlist.Delete();

				break;
			case 2:
				artistPlaylist.Delete();

				break;
			case 3:
				genrePlaylist.Delete();

				break;
			case 4:
				playedSongs.Delete();

				break;
			case 5:
				shuffledSongs.Delete();

				break;
			}
		}
		// Filter by artist
		else if (userChoice == 4)
		{
			unlockedArtist = true;

			artistPlaylist = playlist.FilterByArtist(artistPlaylist);

			cout << "Done";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
		}
		// Filter by genre
		else if (userChoice == 5)
		{
			unlockedGenre = true;
			
			genrePlaylist = playlist.FilterByGenre(artistPlaylist);

			cout << "Done";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
		}
		// Play a playlist
		else if (userChoice == 6)
		{
			// Reset userChoice
			userChoice = 0;

			cout << "Which playlist would you like to play from: " << endl;
			cout << "1) Default Playlist" << endl;
			
			if (unlockedArtist)
			{
				cout << "2) Artist Playlist" << endl;
			}
			if (unlockedGenre)
			{
				cout << "3) Genre Playlist" << endl;
			}
			if (unlockedPlayed)
			{
				cout << "4) Recently Played" << endl;
			}
			if (unlockedShuffled)
			{
				cout << "5) Shuffled Playlist" << endl;
			}

			cin >> userChoice;

			switch (userChoice)
			{
			case 1:
				playedSongs = playlist.Play(playedSongs);

				break;
			case 2:
				playedSongs = artistPlaylist.Play(playedSongs);

				break;
			case 3:
				playedSongs = genrePlaylist.Play(playedSongs);

				break;
			case 4:
				playedSongs = playedSongs.Play(playedSongs);

				break;
			case 5:
				playedSongs = shuffledSongs.Play(playedSongs);

				break;
			}

			unlockedPlayed = true;
		}
		// Shuffle a playlist
		else if (userChoice == 7)
		{
			// Reset userChoice
			userChoice = 0;

			cout << "Which playlist would you like to shuffle: " << endl;
			cout << "1) Default Playlist" << endl;
			
			if (unlockedArtist)
			{
				cout << "2) Artist Playlist" << endl;
			}
			if (unlockedGenre)
			{
				cout << "3) Genre Playlist" << endl;
			}
			if (unlockedPlayed)
			{
				cout << "4) Recently Played" << endl;
			}
			if (unlockedShuffled)
			{
				cout << "5) Shuffled Playlist" << endl;
			}

			cin >> userChoice;

			switch (userChoice)
			{
			case 1:
				shuffledSongs = playlist.Shuffle(shuffledSongs);

				break;
			case 2:
				shuffledSongs = artistPlaylist.Shuffle(shuffledSongs);

				break;
			case 3:
				shuffledSongs = genrePlaylist.Shuffle(shuffledSongs);

				break;
			case 4:
				shuffledSongs = playedSongs.Shuffle(shuffledSongs);

				break;
			case 5:
				shuffledSongs = shuffledSongs.Shuffle(shuffledSongs);

				break;
			}

			unlockedShuffled = true;
		}
		// Store a playlist
		else if (userChoice == 8)
		{
			string fileName;

			// Reset userChoice
			userChoice = 0;

			cout << "Which playlist would you like to display: " << endl;
			cout << "1) Default Playlist" << endl;
			
			if (unlockedArtist)
			{
				cout << "2) Artist Playlist" << endl;
			}
			if (unlockedGenre)
			{
				cout << "3) Genre Playlist" << endl;
			}
			if (unlockedPlayed)
			{
				cout << "4) Recently Played" << endl;
			}
			if (unlockedShuffled)
			{
				cout << "5) Shuffled Playlist" << endl;
			}

			cin >> userChoice;

			switch (userChoice)
			{
			case 1:
				cout << "Please input the filename (including extension): ";
				cin >> fileName;
				cout << endl;

				playlist.Store(playlist, fileName);

				for (int i = 0; i < 3; i++)
				{
					cout << ".";
					Sleep(1000);
				}

				cout << " Successfully stored" << endl;

				break;
			case 2:
				cout << "Please input the filename (including extension): ";
				cin >> fileName;
				cout << endl;

				artistPlaylist.Store(artistPlaylist, fileName);

				for (int i = 0; i < 3; i++)
				{
					cout << ".";
					Sleep(1000);
				}

				cout << " Successfully stored" << endl;

				break;
			case 3:
				cout << "Please input the filename (including extension): ";
				cin >> fileName;
				cout << endl;

				genrePlaylist.Store(genrePlaylist, fileName);

				for (int i = 0; i < 3; i++)
				{
					cout << ".";
					Sleep(1000);
				}

				cout << " Successfully stored" << endl;

				break;
			case 4:
				cout << "Please input the filename (including extension): ";
				cin >> fileName;
				cout << endl;

				playedSongs.Store(playedSongs, fileName);

				for (int i = 0; i < 3; i++)
				{
					cout << ".";
					Sleep(1000);
				}

				cout << " Successfully stored" << endl;

				break;
			case 5:
				cout << "Please input the filename (including extension): ";
				cin >> fileName;
				cout << endl;

				shuffledSongs.Store(shuffledSongs, fileName);

				for (int i = 0; i < 3; i++)
				{
					cout << ".";
					Sleep(1000);
				}

				cout << " Successfully stored" << endl << endl;

				Sleep(1000);

				break;
			}
		}
		// Exit
		else if (userChoice == 9)
		{
			cout << endl << "Storing all playlists";

			for (int i = 0; i < 3; i++)
			{
				cout << ".";
				Sleep(1000);
			}

			playlist.Store(playlist, "playlist.csv");

			if (unlockedArtist)
			{
				artistPlaylist.Store(artistPlaylist, "artistPlaylist.csv");
			}
			if (unlockedGenre)
			{
				genrePlaylist.Store(genrePlaylist, "genrePlaylist.csv");
			}
			if (unlockedPlayed)
			{
				playedSongs.Store(playedSongs, "recentlyPlayedPlaylist.csv");
			}
			if (unlockedShuffled)
			{
				shuffledSongs.Store(shuffledSongs, "shuffledPlaylist.csv");
			}

			unlocked = false;
		}
		else
		{
			cout << endl << "Invalid input, please choose a different number..." << endl << endl;
		}
	}

	return 0;
}