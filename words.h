
#ifndef WORDS_H
#define WORDS_H

#define WORDS_SUCCESS 0
#define WORDS_FAIL 1

#define STAGE 100000
#define INITIAL_HASH 1000000

#define QUICK 1
#define FULL 0

#define VERBOSE 0

#define CORES 1

#define BUFFER_LEN 100000000

typedef int WORDS_STAT;
typedef struct words
{
} WORDPTR;
typedef WORDPTR *WORDS;

#define acronyms       0
#define adjectives     1
#define adverbs        2
#define cia_factbook   3
#define common_stuff   4
#define compound_words 5
#define crosswords     6
#define female_names   7
#define male_names     8
#define nouns          9
#define places        10
#define single_words  11
#define truths        12
#define verbs         13
#define uk_places     14
#define uk_county     15
#define MAX_WORDS     16

typedef enum
{ 
	UNKNOWN = 0,
    ACRONYMS = 1,
    ADJECTIVES = 2,
    ADVERBS = 4,
    CIA_FACTBOOK = 8,
    COMMON_STUFF = 16,
    COMPOUND_WORDS = 32,
    CROSSWORDS = 64,
    FEMALE_NAMES = 128,
    MALE_NAMES = 256,
    NOUNS = 512,
    PLACES = 1024,
    SINGLE_WORDS = 2048,
    TRUTHS = 4096,
    VERBS = 8192,
    UK_PLACE = 16384,
    UK_COUNTY = 32768
} WORD_TYPE;

typedef struct entity
{
	int flag;
    char *name;
	WORD_TYPE type;
    int num_links;              //Number of links to Sub Entities for this Entity
    struct entity **links;      //A dymanic array of long pointers to other Root Entities
} entity;

typedef struct book
{
    char *filename;
    char *name;
    WORD_TYPE type;
} BOOK;

const BOOK books[] = {
        {"data/acronyms.txt", "acronyms", ACRONYMS},
        {"data/adjectives.txt", "adjectives", ADJECTIVES},
        {"data/adverbs.txt", "adverbs", ADVERBS},
        {"data/cia_factbook.txt", "cia_factbook", CIA_FACTBOOK},
        {"data/common_stuff.txt", "common_stuff", COMMON_STUFF},
        {"data/compound_words.txt", "compound_words", COMPOUND_WORDS},
        {"data/crosswords.txt", "crosswords", CROSSWORDS},
        {"data/female_names.txt", "female_names", FEMALE_NAMES},
        {"data/male_names.txt", "male_names", MALE_NAMES},
        {"data/nouns.txt", "nouns", NOUNS},
        {"data/places.txt", "places", PLACES},
        {"data/single_words.txt", "single_words", SINGLE_WORDS},
        {"data/truths.txt", "truths", TRUTHS},
        {"data/verbs.txt", "verbs", VERBS},
        {"data/uk_places", "verbs", UK_PLACE},
        {"data/uk_county", "verbs", UK_COUNTY},
    };


const char *word_type_str(WORD_TYPE);
WORDS_STAT initialise (WORDS * words);
WORDS_STAT load (WORDS words, const char *filename, const WORD_TYPE type);
WORDS_STAT save (const WORDS words, char *filename);
WORDS_STAT search (const WORDS words, char *word);
entity    *find_word (const WORDS words, char *word);
WORD_TYPE  cat_word (const WORDS words, char *word);
WORDS_STAT dump (const WORDS words);
WORDS_STAT dump_json (const WORDS words);
WORDS_STAT dump_formatted (const WORDS w);
WORDS_STAT dump_txt (const WORDS w);
WORDS_STAT word_search (const WORDS w, long nth_order, long quick, char *entity1, char *entity2);
WORDS_STAT word_search_r (const WORDS w, long nth_order, long quick, char *entity1, char *entity2);
int create_in_txt (int num_lines, char *file);
WORDS_STAT read_files (WORDS w, int number);
#define read_all_files(a) read_files(a,MAX_WORDS)
#endif
