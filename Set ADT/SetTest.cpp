
#include "Set.h"
using namespace std;

/* Macro to explicity print tests that are run along with colorized result. */
#define TEST(EX) (void)((fprintf(stdout, "(%s:%d) %s:", __FILE__, __LINE__,\
                 #EX)) && ((EX && fprintf(stdout, "\t\x1b[32mPASSED\x1b[0m\n"))\
                 || (fprintf(stdout, "\t\x1b[31mFAILED\x1b[0m\n")) ))

/**
 * Sanity test on the multiway trie.
 */
void testSanity() {
    MultiwayTrieSet mt;
    mt.insert("test");
    TEST(mt.contains("test") == true);
    TEST(mt.size() == 1);
    mt.erase("test");
    TEST(mt.size() == 0);

    mt.insert("test789");
    TEST(mt.size() == 1);
    mt.insert("test123");
    mt.insert("test456");

    TEST(mt.size() == 3);
    mt.erase("test123");
    TEST(mt.size() == 2);
    TEST(mt.contains("test") == false);
    mt.erase("test");
    TEST(mt.contains("test") == false);
    TEST(mt.contains("test123") == false);
    TEST(mt.contains("test456") == true);
    TEST(mt.size() == 2);




    RedBlackTreeSet rb;
    rb.insert("test");
    TEST(rb.contains("test") == true);
    TEST(rb.size() == 1);
    rb.erase("test");
    TEST(rb.size() == 0);
    rb.insert("test");
    TEST(rb.contains("test") == true);
    TEST(rb.size() == 1);
    rb.insert("test123");
    TEST(rb.contains("test123") == true);
    rb.erase("test");
    TEST(rb.contains("test") == false);
    TEST(rb.size() == 1);
    rb.erase("test123");
    TEST(rb.size() == 0);



    LinkedListSet lls;
    lls.insert("test");
    TEST(lls.contains("test") == true);
    TEST(lls.size() == 1);
    lls.erase("test");
    TEST(lls.size() == 0);

    HashTableSet hts;
    hts.insert("test");
    TEST(hts.contains("test") == true);
    TEST(hts.size() == 1);
    hts.erase("test");
    TEST(hts.size() == 0);

    ArrayListSet als;
    als.insert("test");
    TEST(als.contains("test") == true);
    TEST(als.contains("123") == false);
    TEST(als.contains("123test") == false);
    TEST(als.size() == 1);
    als.erase("test");
    TEST(als.contains("test") == false);
    TEST(als.size() == 0);
}


/**
 * Test the Set implementations
 */
int main() {
    testSanity();
}