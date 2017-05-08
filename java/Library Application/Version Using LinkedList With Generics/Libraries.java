/**
 * The Libraries class implements a collection of all libraries
 * */

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

public class Libraries {

    public Library[] libraries;        // a collection of libraries of type array
    public int numberOfLibraries;      // number of libraries in collection

    /* Constructor */
    public Libraries(int numberOfLibraries){
        this.numberOfLibraries = numberOfLibraries;
        this.libraries = new Library[this.numberOfLibraries];
    }

    //the method takes two String params
    //it reads the file with fileName and creates an object of type Library
    //where the Library has the name defined by the string libraryName
    public Library buildLibraryFromFile(String libraryName, String fileName) {

        Library library = new Library<Book>(libraryName);

        String path = System.getProperty("user.dir");
        Book book = null;
        String s;
        
        try (BufferedReader br = new BufferedReader(new FileReader(fileName))) {
        //try (BufferedReader br = new BufferedReader(new FileReader("./Root/" + fileName))) {
        // if you run locally on your environment use: new FileReader(path + "/src/" + fileName)

            while ((s = br.readLine()) != null) { 
                String[] tok = s.split(",");

                if(tok.length == 2 && (Integer.parseInt(tok[1]) <= 100 && Integer.parseInt(tok[1]) >= -100)){ // validates lines
                    try{
                        book = new Book(tok[0],Integer.parseInt(tok[1])); 
                        book.setLibrary(library);
                        library.libraryItems.add(book);    
                    } catch(Exception e){
                        System.out.println(e.getMessage());
                    }
                }
                
            }

        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
        return library;
    }

    //the method returns the first library where the book is found
    //this method checks only if the book is part of the library inventory
    public Library isThereBookInLibraries(Book book) {
        Library searchResult = null;
        search: // returning first library where the book is found
        for (int i = 0; i < this.numberOfLibraries ; i++) {
            
                ListIterator<Book> listIterator = libraries[i].libraryItems.listIterator();
                while (listIterator.hasNext()){      
        
                    if(book.equals(listIterator.next())){
                        searchResult = libraries[i];
                        break search;  
                    }
                }      
        }
       return searchResult;
    }

    //the method takes three params: a book and two dates that defines the desire
    //rented perioad. The method returns the first library where the book
    //is available and can be rented
    public Library rentBookAvailable(Book book, String requestDate, String dueDate) {
    /**
     * If the book is not part of library inventory or the book is already borrowed, the request is sent to another library. If
     * the request cannot be satisfied, then it is dropped.
     * */
        Library foundLibrary = null;
        Book tempBook = null;

        search: // returning first library where the book is available
        for (int i = 0; i < this.numberOfLibraries ; i++) {
                
                /* If cannot be borrowed, continue search */
                if(this.libraries[i].rentRequest(book,requestDate,dueDate) == true){
                    foundLibrary = this.libraries[i];
                    break search;
                }
       }     
        return foundLibrary;
    }

    /**
     * Equals function
     * @param object an object indicating an object to compare with 'this' object
     * @return a boolean indicating whether the Libraries are equal
     * */
    @Override
    public boolean equals(Object o) { 
        if (this == o)
            return true;
        if (o == null)
            return false;
        if (getClass() != o.getClass())
            return false;
        Libraries other = (Libraries) o;
        if (this.libraries.equals(other.libraries) && this.numberOfLibraries == other.numberOfLibraries){  
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

        result = prime * result + new Integer(this.numberOfLibraries).hashCode();
        result = prime * result + this.libraries.hashCode(); 
      
        return result;
    }

    /**
     * Returning a string of the variables in the library
     * @return a String indicating the libraries list and number
     * */
    @Override
    public String toString() {
        String s = "\n";

        for (int i = 0; i < this.numberOfLibraries ; i++) {
            s+=this.libraries[i];
        }
        
        return s;
    }

}
