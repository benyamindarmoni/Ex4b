
#include <iostream>
using namespace std;

#include "play.hpp"
#include "DummyChoosers.hpp"
#include "DummyGuessers.hpp"
#include "SmartGuesser.hpp"
#include "badkan.hpp"
#define COMMA ,

using namespace bullpgia;

int main() {

	badkan::TestCase testcase;
	int grade=0;
	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0) {

		// BASIC TESTS - DO NOT CHANGE
			ConstantChooser c1234{"1234"}, c12345{"12345"}, c9999{"9999"},c1432{"1432"}, c98765{"98765"}, c192837{"192837"};;
		ConstantGuesser g1234{"1234"}, g12345{"12345"}, g9999{"9999"},g98765{"98765"};

		testcase.setname("Calculate bull and pgia")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","1234"), "4,0")      // 4 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1234","4321"), "0,4")      // 0 bull, 4 pgia
		;

		testcase.setname("Play with dummy choosers and guessers")
		.CHECK_EQUAL(play(c1234, g1234, 4, 100), 1)      // guesser wins in one turn.
		.CHECK_EQUAL(play(c1234, g9999, 4, 100), 101)    // guesser loses by running out of turns 
		.CHECK_EQUAL(play(c1234, g12345, 4, 100), 101)   // guesser loses technically by making an illegal guess (too long).
		.CHECK_EQUAL(play(c12345, g1234, 4, 100), 0)     // chooser loses technically by choosing an illegal number (too long).
		;

		testcase.setname("Play with smart guesser");
		RandomChooser randy;
		SmartGuesser smarty;
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(randy, smarty, 4, 100)<=10, true);  // smarty should always win in at most 10 turns!
		}
			testcase.setname("MyTests")      //!!!!!!!!!!!!!!!!!	
        	.CHECK_OUTPUT(calculateBullAndPgia("2610","2610"), "4,0")      // 4 bull, 0 pgia
	    	.CHECK_OUTPUT(calculateBullAndPgia("1230","1234"), "3,0")      // 3 bull, 0 pgia
	    	.CHECK_OUTPUT(calculateBullAndPgia("2357","4321"), "1,1")      // 1 bull, 1 pgia
	    	.CHECK_OUTPUT(calculateBullAndPgia("2610","1234"), "0,2")      // 0 bull, 2 pgia
			.CHECK_OUTPUT(calculateBullAndPgia("9876","9786"), "2,2")      // 2 bull, 2 pgia
	    	.CHECK_OUTPUT(calculateBullAndPgia("4322","4321"), "3,0")      // 3 bull, 1 pgia
     		.CHECK_OUTPUT(calculateBullAndPgia("0406","3657"), "0,1")      // 0 bull, 1 pgia
			.CHECK_OUTPUT(calculateBullAndPgia("1230","1234"), "3,0")      // 3 bull, 0 pgia
			.CHECK_OUTPUT(calculateBullAndPgia("0406","0406"), "4,0")      // 4 bull, 0 pgia
        	.CHECK_OUTPUT(calculateBullAndPgia("0000","0000"), "4,0")      // 4 bull, 0 pgia
	     	.CHECK_OUTPUT(calculateBullAndPgia("9976","9765"), "1,2")      // 1 bull, 2 pgia
			.CHECK_OUTPUT(calculateBullAndPgia("1122","2211"), "0,4")      // 0 bull, 4 pgia
			.CHECK_OUTPUT(calculateBullAndPgia("3961","9661"), "2,1")      // 2 bull, 1 pgia
			.CHECK_OUTPUT(calculateBullAndPgia("1122","2211"), "0,4")      // 0 bull, 4 pgia
			.CHECK_OUTPUT(calculateBullAndPgia("9875","9871"), "3,0")      // 3 bull, 0 pgia
			.CHECK_OUTPUT(calculateBullAndPgia("1298","2198"), "2,2")      // 2 bull, 2 pgia
			.CHECK_OUTPUT(calculateBullAndPgia("9758","8795"), "1,3")      // 1 bull, 3 pgia
			//********************************************************************************
			/*	ConstantChooser c1234{"1234"}, c12345{"12345"}, c9999{"9999"},c1432{"1432"}, c98765{"98765"}, c192837{"192837"};;
		ConstantGuesser g1234{"1234"}, g12345{"12345"}, g9999{"9999"},g98765{"98765"};
*/
			.CHECK_EQUAL(play(c192837,g1234, 4, 50), 0)      // chooser loses technically by choosing an illegal number (too long).
		.CHECK_EQUAL(play(c192837,g1234, 6, 50), 51)    //  guesser loses technically by making an illegal guess (too long).
		.CHECK_EQUAL(play(c1432, g1234, 4, 100), 101)   // guesser loses by running out of turns 
/*	*/	
	  .CHECK_EQUAL(play( c98765, g1234, 4, 100), 0)      // chooser loses technically by choosing an illegal number (too short).
		.CHECK_EQUAL(play(c98765, g12345, 5, 100), 101)     //  guesser loses by running out of turns
		.CHECK_EQUAL(play(c1234, g9999, 4, 100), 101)     // guesser loses by running out of turns
		.CHECK_EQUAL(play(c12345, g98765, 4, 100), 0)    // chooser loses technically by choosing an illegal number (too long).
		.CHECK_EQUAL(play(c1234, g9999, 4, 75), 76)    	 // guesser loses by running out of turns
		.CHECK_EQUAL(play(c1432, g9999, 3, 10), 0)    	 //chooser loses technically by choosing an illegal number (too short).
			
		.CHECK_EQUAL(play(c1432, g1234, 4, 90), 91)    		 // guesser loses by running out of turns
		.CHECK_EQUAL(play(c1432, g1234, 4, 9), 10)    // guesser loses by running out of turns
	.CHECK_EQUAL(play(c98765, g98765, 5, 32), 1)  	 //guesser wins in one turn.
	
		;

    grade = testcase.grade();
	} else {
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: "  << grade << endl;
	return 0;
}
