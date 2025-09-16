#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char stageName[50];
} MemberName;

typedef struct {
    MemberName members[4];
    char agencyName[50];
    int debutYear;
} Artist;

typedef struct {
    char songTitle[50];
    int releaseYear;
} Song;

typedef struct SongNode {
    Song songInfo;
    struct SongNode* nextSong;
} SongNode, *SongStack;

typedef struct {
	Song List[20];
} SongList;

typedef struct {
    SongStack top; // Representation of Stack in a Linked List implementation
    Artist artistInfo;
} Album;

Album initializeAlbum();
void populateAlbum(Album *ae);
int isEmpty(Album *ae);
void pushSong(Album *ae, Song newSong);
void popSong(Album *ae);
Song peekSong(Album *ae);
void displayAlbum(Album ae);

int main(){
	Album aespa;
	Song topSong;
	
	aespa = initializeAlbum();
	
	populateAlbum(&aespa);
	
	displayAlbum(aespa);
	
	topSong = peekSong(&aespa);
    printf("Peek (Top Song): %s (%d)\n\n", topSong.songTitle, topSong.releaseYear);
    
    printf("Press any key to continue...\n\n");
    
	
	popSong(&aespa);
	popSong(&aespa);
	popSong(&aespa);
	popSong(&aespa);
	popSong(&aespa);
	
	displayAlbum(aespa);
	
	topSong = peekSong(&aespa);
    printf("Peek (Top Song): %s (%d)\n\n", topSong.songTitle, topSong.releaseYear);
	
	return 0;
}

Album initializeAlbum(){
	Album ae = {NULL, {{{""},{""},{""},{""}}, "", 0}};
	
	printf("Initalized Album.\n");
	return ae;
}

void populateAlbum(Album *ae){
    Artist aespaInfo = {{{"Karina"}, {"Winter"}, {"Ningning"}, {"Giselle"}}, 
                        "SM Entertainment", 2020};

    SongList library = {{
    	{"Rich Man", 2025},
        {"Dirty Work", 2025},
        {"Supernova", 2024},
        {"Armageddon", 2024},
        {"Whiplash", 2024},
        {"Drama", 2023},
        {"Better Things", 2023},
        {"Welcome To MY World", 2023},
        {"Spicy", 2023},
        {"Illusion", 2022},
        {"Girls", 2022},
        {"Life's Too Short", 2022},
        {"Savage", 2021},
        {"Next Level", 2021},
        {"Black Mamba", 2020}
    }};

    ae->artistInfo = aespaInfo;

    for(int i = 0; i < 15; i++){
        pushSong(ae, library.List[i]);
        printf("Added song to album: %s (%d)\n", 
               library.List[i].songTitle, library.List[i].releaseYear);
    }
}


int isEmpty(Album *ae){
	return (ae->top == NULL) ? 1 : 0;
}

void pushSong(Album *ae, Song newSong){
	SongStack newNode = (SongStack)malloc(sizeof(SongNode));
	newNode->songInfo = newSong;
	newNode->nextSong = ae->top;
	
	ae->top = newNode;
}

void popSong(Album *ae){
	if(!isEmpty(ae)){
		SongStack temp = ae->top;
		
		printf("Removed song: %s (%d)\n", temp->songInfo.songTitle, temp->songInfo.releaseYear);
		
		ae->top = temp->nextSong;
		
		free(temp);
	} else {
		printf("Album is empty. Nothing to remove.\n");
	}
}

Song peekSong(Album *ae){
    Song dummy = {"N/A", 0};
    
    if(!isEmpty(ae)){
        return ae->top->songInfo;
    }
    
    return dummy;
}

void displayAlbum(Album ae){
    SongStack trav;
    int track = 1;

    printf("\n========= Album Info ==========\n");
    printf("Group Name   : %s\n", "Aespa");
    printf("Agency       : %s\n", ae.artistInfo.agencyName);
    printf("Debut Year   : %d\n", ae.artistInfo.debutYear);
    printf("Members      : %s, %s, %s, %s\n",
           ae.artistInfo.members[0].stageName,
           ae.artistInfo.members[1].stageName,
           ae.artistInfo.members[2].stageName,
           ae.artistInfo.members[3].stageName);

    printf("\n========== Tracklist ==========\n");
    printf("%-5s %-20s %-10s\n", "No.", "Song Title", "Year");
    for(trav = ae.top; trav != NULL; trav = trav->nextSong){
        printf("%-5d %-20s %-10d\n", track++, trav->songInfo.songTitle, trav->songInfo.releaseYear);
    }
    printf("===============================\n\n");
}