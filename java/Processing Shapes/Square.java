/** Interface for creating lambda */
interface SquareProperty{

    double get(double length);

}

/** This class creates a shape of type Square */
public class Square implements Shape{ 

    /** Square length */
    private double length;


    /**
     * Constructor accepts an double for the length, throws exception if data is not valid
     * @param length A positive double representing the length of the Square
     * */
    public Square(double length) throws MyException{

            if (length == 0)
                throw new MyException("The length of the Square cannot be equal to zero. The value passed: "+length); 
            if (length < 0)
                throw new MyException("The length of the Square cannot be negative. The value passed: "+length);  
            if (length > 0)
                this.length = length;

    }

    /** 
     * Getting the lenght of particular Square
     * @param lenght A positive double representing the lenght of the square
     * @param s SquareProperty interface indicating particular Square
     * @return a double indicating the lenght of the Square
     * */
    public double SquareValue(double length, SquareProperty s){
        return s.get(length);
    }

    /**
     * Getting the perimeter of the Square
     * @return a double indicating the perimeter of the shape
     * */
    public double getPerimeter() {
       SquareProperty perimeter = length -> 4 * this.length;
       return this.SquareValue(this.length, perimeter);
    }

    /**
     * Returning a string of the variable in the Square
     * @return a String indicating the length of the Square + its perimeter
     * */
    @Override
    public String toString(){
       return String.format("Square {l=%.2f} perimeter=%.2f", this.length, this.getPerimeter());
    }

    /**
     * Unique hashCode
     * @return a unique integer hashCode
     * */
    @Override
    public int hashCode(){

        /** integer to generate hashcode */
        final int prime = 31;

        /** integer to generate hashcode */
        int result = 17;

        result = prime * result + new Double(this.length).hashCode(); 
      
        return result;
    }

    /**
     * Equals function
     * @param object an object indicating an object to compare with 'this' object
     * @return a boolean indicating whether the Squares are equal
     * */
    @Override
    public boolean equals(Object object){
      if (this == object)
            return true;
        if (object == null)
            return false;
        if (getClass() != object.getClass())
            return false;
        Square other = (Square) object;
        if (this.length != other.length)
            return false;
        return true;
    }

}