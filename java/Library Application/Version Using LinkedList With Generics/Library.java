/**
 * The Library class implements a library that stores libraryItems
 * */

import java.util.Iterator;
import java.util.Vector;
import java.util.*;

public class Library<T extends Book> implements MaxTagValue {


    String       libraryName;   // library name
    LinkedList<T> libraryItems; // list of contained libraryItems
  
    //ctr. that takes as param only the libraryName
    public Library (String libraryName) {
        this.libraryName = libraryName;
        libraryItems = new LinkedList<T>();
    }

    //this method search all the libraryItems froma library
    //and returns an integer that is the maximum value tag
    public int findMaximumValueTag() {
        int maxElement = -100;
        T temporaryBook = null;
        ListIterator<T> listIterator = this.libraryItems.listIterator();
        while (listIterator.hasNext()){
            temporaryBook = listIterator.next();
            if(temporaryBook.valueTag > maxElement){
                maxElement = temporaryBook.valueTag;
            }
        }
        return maxElement;
    }
    
    //the method takes three params: a book and two dates
    //the method returns true if the book is available in this library
    //from requestData up to dueDate
    public boolean rentRequest(T wanted, String requestDate, String dueDate) {
        boolean resultRentRequest = false;
        try {
            Helper.checkDate(requestDate);
            Helper.checkDate(dueDate);

            /* Checks if the dates are logically correct */
            if (Helper.timeDifference(Helper.getCurrentDate(),requestDate) >= 0) {

                seachItemCopy: // searches for the first found desired book to rent
                for ( T i : libraryItems) {
                
                        if(wanted.equals(i) && i.rs == null){
                             resultRentRequest = true;
                             i.rentBook(requestDate, dueDate, this);
                             System.out.println("Book has been borrowed: "+i);
                             break seachItemCopy;
                        } else if(wanted.equals(i) && i.rs != null){

                            System.out.println(Helper.printUnavailable(wanted, requestDate)+" in "+libraryName+" library.");
                        
                        }
                }
            } else {
                System.out.println("Request date cannot be earlier than today.");
            }
            
        } catch (DateFormatException e) {  
            System.out.println(wanted + e.getMessage());
        }
        return resultRentRequest;
    }

    /**
     * libraryName function
     * @return a String indicating the libary name
     * */
    public String libraryName(){
      return this.libraryName;
    }

    /**
     * Equals function
     * @param object an object indicating an object to compare with 'this' object
     * @return a boolean indicating whether the libraries are equal
     * */
    @Override
    public boolean equals(Object o) { 
        if (this == o)
            return true;
        if (o == null)
            return false;
        if (getClass() != o.getClass())
            return false;
        Library other = (Library) o;
        if (this.libraryName.equals(other.libraryName) && this.libraryItems.equals(other.libraryItems)){  
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

        result = prime * result + new String(this.libraryName).hashCode();
        result = prime * result + this.libraryItems.hashCode();
      
        return result;
    }

    /**
     * Returning a string of the variables in the library
     * @return a String indicating the library name and the list of libraryItems that library contains
     * */
    @Override
    public String toString() {

        String s = "Library = "+this.libraryName+"\n[";
        ListIterator<T> listIterator = this.libraryItems.listIterator();
    
          while (listIterator.hasNext()){
            s+="\n"+listIterator.next();
          }

        s+="\n]\n";
        
        return s;
    }
}
