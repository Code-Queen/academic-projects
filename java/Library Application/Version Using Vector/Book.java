/**
 * The Book class implements a book that can be stored in a library
 * */

import java.util.*;

class Book {

    String       bookName;    // the book name
    int          valueTag;    // an integer between -100 and 100
    Library      library;     // the library having this book it its inventory
    RentSettings rs;          // rent settings

    public Book(String bookName, int valueTag) {
        this.bookName = bookName;
        this.valueTag = valueTag;
    }


    // set the rent dates; if dates are not valid catch DateFormatException and return false,
    // if rentDate > dueDate catch RentPeriodException and return false
    // if one the exceptions occur there is no RentSettings object
    public boolean rentBook(String rentDate, String dueDate, Library library) {

        boolean rentResult = false;
        RentSettings rs = null;

        try{
            Helper.checkDate(rentDate);
            Helper.checkDate(dueDate);

            /* Check if the dates are logically correct */
            if (Helper.timeDifference(rentDate,dueDate) < 0) { 
                try {
                    throw new RentPeriodException("Rent date must be earlier/less than due date.");
                } catch (RentPeriodException e) {
                    e.getMessage();
                }
            } else{

                /* Create Rent Settings */
                try{
                    this.rs = new RentSettings(rentDate, dueDate, library);
                    rentResult = true;
                } catch (DateFormatException | RentPeriodException e) {
                e.getMessage();
                 }
            }

        } catch (DateFormatException e) {
                e.getMessage();
        }
        return rentResult;
    }

    // destroy the RentSettings object for this book
    public void returnBook(Library library) {
        if (this.library == library){
            this.rs = null;
        }
    }

    // return the date when this book is available
    public String availableDate(Library library) {
        String temp;
        if(this.rs.dueDate != null){
            temp = this.rs.dueDate;
        } else{
            temp = Helper.getCurrentDate();
        }
        return temp;
    }

    // returns true if the current date is greater than the due date
    public boolean isBookOverdue() {
        Boolean result = false;
        try{
            result = Helper.timeDifference(Helper.getCurrentDate(),this.rs.dueDate) < 0;
        } catch (DateFormatException e) {
            e.getMessage();
        }
        return result;
    }

    // returns true is the book is rented
    public boolean isRented(Library l) {
        if (this.library == l && this.rs != null) {
            return true;  
        } else {
            return false;
        }
    }

    // getter for RentSettings rs object
    public RentSettings getRs() {
       return this.rs;
    }

    // setter for RentSettings rs object
    public void setRs(RentSettings rs) {
       this.rs = rs;
    }

    /**
     * setLibrary function
     * @param library a library indicating the library that holds the book in its inventory
     * */
    public void setLibrary(Library library){
        this.library = library;
    }

    /**
     * Equals function
     * @param object an object indicating an object to compare with 'this' object
     * @return a boolean indicating whether the books are equal
     * */
    @Override
    public boolean equals(Object o) { 
        if (this == o)
            return true;
        if (o == null)
            return false;
        if (getClass() != o.getClass())
            return false;
        Book other = (Book) o;
        if (this.bookName.equals(other.bookName) && this.valueTag == other.valueTag){
         return true;
        } else {
            return false;
        }  
    }

    /**
     * Unique hashCode
     * @return a unique integer hashCode
     * */
    @Override
    public int hashCode() {
        /** integer to generate hashcode */
        final int prime = 31;

        /** integer to generate hashcode */
        int result = 17;

        result = prime * result + new String(this.bookName).hashCode();
        result = prime * result + new Integer(this.valueTag).hashCode();
        result = prime * result + this.library.hashCode();  
        result = prime * result + this.rs.hashCode(); 
      
        return result;

    }

    /**
     * Returning a string of the variables in the book
     * @return a String indicating the book name, book tag value, the library name
     * having this book it its inventory and rent settings if applicable
     * */
    @Override
    public String toString() {

        String s = "("+this.bookName+", "+this.valueTag;
        if(this.library != null){
            s = s+" => "+this.library.libraryName();
        }
        s = s+")";
        if(this.rs !=null){
        s = s+rs;
        }
        
        return s;
    }

    /**
     * bookName function
     * @return a String indicating the book name and its value tag
     * */
    public String bookName() {
        return "(" + this.bookName + ", " + this.valueTag + ')';
    }

    /**
     * getRentDate function
     * @return a String indicating the date when the book was rented if there're rent settings
     * */
    public String getRentDate(){
        if(this.rs != null){
            return this.rs.rentDate;
        } else {
            return null;
        }
    }

    /**
     * getDuetDate function
     * @return a String indicating the date when is due if there're rent settings
     * */
    public String getDueDate(){   
        if(this.rs != null){
            return this.rs.dueDate;
        } else {
            return null;
        } 
    }
    
    /**
     * geBorrowed function
     * @return a boolean indicating if rent settings contain if the book is borrowed
     * */        
    public boolean getBorrowed(){
        return this.rs.borrowed;
    }


    //inner class that defines the rented perioad and book availability 
    private class RentSettings {

        private String rentDate;          // date when the item is requested
        private String dueDate;           // date when the item must be returned
        private boolean borrowed = false; // true if the item is rented

        //default ctr
        private RentSettings() throws DateFormatException {
           
        }

        // private ctr must throw DateFormatException and RentPeriodException
        private RentSettings(String rentDate, String dueDate, Library library)
                throws DateFormatException, RentPeriodException {
            try{
                Helper.checkDate(rentDate);
                Helper.checkDate(dueDate);

                /* Check if the library asked is the library to which the book belongs */
                if(library.equals(Book.this.library)){

                    /* Check if dates are logically corect */
                    if (Helper.timeDifference(Helper.getCurrentDate(),rentDate) >= 0) {
                        if (Helper.timeDifference(rentDate,dueDate) < 0) { 
                            try {
                                throw new RentPeriodException("Rent date must be earlier/less than due date.");
                            } catch (RentPeriodException e) {
                                e.getMessage();
                            }
                        } else{
                            this.rentDate = rentDate;
                            this.dueDate = dueDate;
                            borrowed = true;
                        }
                    } else {
                        System.out.println("Request date cannot be earlier than today.");
                    }
                } else{
                    System.out.println("Book must belong to the library requested.");
                }
             } catch (DateFormatException e) {
                e.getMessage();
            }
            
        }

        /**
        * Equals function
        * @param object an object indicating an object to compare with 'this' object
        * @return a boolean indicating whether the rs are equal
        * */
        @Override
        public boolean equals(Object o) { 
            if (this == o)
                return true;
            if (o == null)
                return false;
            if (getClass() != o.getClass())
                return false;
            RentSettings other = (RentSettings) o;
            if (this.rentDate.equals(other.rentDate) && this.dueDate.equals(other.dueDate) && this.borrowed == other.borrowed){  
                return true;
            } else{
                return false;
            }
        }

        /**
        * Unique hashCode
        * @return a unique integer hashCode
        * */
        @Override
        public int hashCode() {
            /** integer to generate hashcode */
            final int prime = 31;

            /** integer to generate hashcode */
            int result = 17;

            result = prime * result + new String(this.rentDate).hashCode();
            result = prime * result + new String(this.dueDate).hashCode();
            if (this.borrowed == true){ 
                result = prime * result + 31;
            } else {
                result = prime * result + 17;
            }
      
            return result;
        }

        /**
        * Returning a string of the variables in the rs
        * @return a String indicating the rs : rent date, due date, library name where book is borrowed
        * */
        @Override
        public String toString() {
            return " RentSettings ("+this.rentDate+","+this.dueDate+","+library.libraryName()+","+this.borrowed+")";
        }
    }
}
