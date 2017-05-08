/**
 * The Helper class implements helping dates validation methods and book status print methods
 * */

import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

public class Helper {

    /**
     * Looks if the date is in right format
     * @param date a String indicating the date
     * @return a boolean indicating if the date is in right format
     * */
    public static boolean isValidDate(String date) {
        boolean valid = true;
        DateFormat formatter = new SimpleDateFormat("MM/dd/yyyy");
        formatter.setLenient(false);
        try {
            formatter.parse(date);
        } catch (ParseException e) {
            valid = false;
        }
        return valid;
    }

    /**
     * Checks if the date is in right format
     * @param date a String indicating the date
     * @return a boolean indicating if the date is in right format
     * */
    public static void checkDate(String date) throws DateFormatException {

        if (!Helper.isValidDate(date)) {
                throw new DateFormatException(" Invalid data format " + date + " it should be MM/dd/yyyy");
        }
    }

    /**
     * Checks time difference between two dates
     * @param date1 a String indicating the date1
     * @param date2 a String indicating the date2
     * @return a long the differnece between two dates
     * */
    public static long timeDifference(String date1, String date2) throws DateFormatException {

        SimpleDateFormat dateFormat = new SimpleDateFormat("MM/dd/yyyy");

        if ( !isValidDate(date1) || !isValidDate(date2)) {
            throw new DateFormatException("Invalid data format: " + date1 + " and " + date2 + " should be MM/dd/yyyy");
        }

        Date d1 = null;
        Date d2 = null;
        long diffDays = 0;

        try {
            d1 = dateFormat.parse(date1);
            d2 = dateFormat.parse(date2);

            //in milliseconds
            long diff = d2.getTime() - d1.getTime();
            diffDays = diff / (24 * 60 * 60 * 1000);
            return diffDays;

        } catch (Exception e) {
            e.printStackTrace();
        }
        return diffDays;
    }

    /**
     * Gets current date
     * @return a String indicating current date
     * */
    public static String getCurrentDate() {
        DateFormat dateFormat = new SimpleDateFormat("MM/dd/yyyy");
        //get current date time with Date()
        Date date = new Date();
        return dateFormat.format(date);
    }

    /**
     * Prints available book indicating the date and library
     * @param book a Book indicating the available book
     * @param rentDate a String indicating the date when the book is availabe to be rented
     * @param library a Library indicating the library where the book can be rented
     * @return a String indicating the book name, value tag, the day it is available to be rented and the library
     * */
    public static String printAvailable(Book book, String rentDate, Library library) {
        return "Book (" + book.bookName + ", "+ book.valueTag +") is availble at " +
                rentDate + " from library: " + library.libraryName;
    }

    /**
     * Prints unavailable book indicating the date that it is desired
     * @param book a Book indicating the desired book
     * @param rentDate a String indicating the date when the book is desired
     * @return a String indicating that the book name is not available for desired date
     * */
    public static String printUnavailable(Book book, String rentDate) {
        return "Book " + book + " is not availble for " + rentDate;
    }

    /**
     * Prints nonexistent book
     * @param book a Book indicating the nonexistent book
     * @return a String indicating the book does not exist
     * */
    public static String printNonexistent(Book book) {
        return "Book " + book + " does not exist! ";
    }

}