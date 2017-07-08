import java.util.Scanner;
import java.lang.Math.*;

public class TalkingClock {
	public static final String[] ones = {
		//array of names for ints in 'ones' digit place
		//of an int, goes to 19 to be used for hours
		//and for any amount of minutes less than twenty
		//zero is unused and left as an empty string
		"",
		" one",
		" two",
		" three",
		" four",
		" five",
		" six",
		" seven",
		" eight",
		" nine",
		" ten",
		" eleven",
		" twelve",
		" thirteen",
		" fourteen",
		" fifteen",
		" sixteen",
		" seventeen",
		" eighteen",
		" nineteen"
	};
	public static final String[] tens = {
		//array of tens digit place of minutes, and 10
		//being unused and left as empty string
		" oh",
		"",
		" twenty",
		" thirty",
		" fourty",
		" fifty"
	};
	public static void main(String[] args) {
		//takes in time in 24 hr format and outputs time in 12 hr
		//input format hh:mm
		//output format "It's 'hour' 'minute' am/pm"

		//input from command line
		Scanner input = new Scanner(System.in);

		//take in input and split hours and minutes
		System.out.print("Enter a time: ");
		String in = input.next();
		String time[] = in.split(":");

		//parse hours as int and minutes as seperate digits
		int hour = Integer.parseInt(time[0]);
		char[] min = time[1].toCharArray();
		int ten = Character.getNumericValue(min[0]);
		int one = Character.getNumericValue(min[1]);

		boolean am = true;

		if(ten == 1){
			one += 10;//if minutes is a 'teen' set one to appropriate teen
		}
		if(ten == 0 && one == 0){
			ten = 1;//if total minutes is zero set ten to empty string instead of 'oh'
		}

		if(hour > 11){
			am = false;//set am/pm based on hours
		}
		if(hour > 12 || hour == 0) {
		hour = Math.abs(hour - 12);//change hour from 24hr format to 12hr format
		}

		//print time
		System.out.print("It's" + ones[hour] + tens[ten] + ones[one]);
		if(am){
			System.out.println(" AM");
		}
		else {
			System.out.println(" PM");
		}
		input.close();
	}
}