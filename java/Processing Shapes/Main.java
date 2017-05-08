/**
 *  Java Processing Shapes Program
 *
 *  This program:
 *  >Builds Shapes From File
 *  >Deletes Triangle with min perimeter and Circle with max perimeter
 *  >Calculates All Perimeter of Parallelograms ans All Perimeter of Triangles
 *  >Prints Sorted Shapes
 * */
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

/** Interface for creating Shapes */
interface Shape {

    public double getPerimeter();

}

public class Main {

    /** 
     * Comparator for Shapes by Class Name and Perimiter within a Shape 
     * */
    public static Comparator<Shape> ShapeComparator
                          = new Comparator<Shape>() {

        /** 
         * Comparing two Shapes
         * @param shape1 A Shape first Shape to compare
         * @param shape2 A Shape indicating second Shape to compare
         * @return an integer indicating the comparison result between the two Shapes
         * */                   
        public int compare(Shape shape1, Shape shape2) {

            /** integer to store the final result */
            int result;

            /** integer to store the result of the sorting by Class Name */
            int nameSortResult;

            /** name of the first shape class */
            String shapeName1 = shape1.getClass().getName();

            /** name of the second shape class */
            String shapeName2 = shape2.getClass().getName();

            /** perimiter of the first shape */
            Double shapePerimeter1 = shape1.getPerimeter();

            /** perimiter of the second shape */
            Double shapePerimeter2 = shape2.getPerimeter();

            /** Sorting by Class Name in Alphabetical order */
            nameSortResult = shapeName1.compareTo(shapeName2); 

            /** Sorting within a Class Name by Perimiter in Ascending Order: if the same class name - sort by perimiter */
            if (nameSortResult != 0) {
               result = nameSortResult;
            } else {       
               result =  shapePerimeter1.compareTo(shapePerimeter2);
            }

          return result;

        }

    };

    /** Main method: executes 4 Tasks: 
     *       1. Read the file Shapes.txt, create the shapes and store them in your data
     *          structure. Then print all the shapes and their perimeters.
     *       2. Delete from all shapes the triangle with the minimum perimeter from all
     *          triangles and the circle with the maximum perimeter from all circles.
     *       3. Calculate the perimeter of all parallelograms. Calculate the perimeter of all
     *          triangles.
     *       4. Print all the shapes sorted alphabetically. For the same shapes print them
     *          sorted (ascending) based on the perimeter values. 
     * */
    public static void main(String[] args) {

        /** List for storing all the Shapes */
        List<Shape> myShapes = new LinkedList<Shape>();

        /** Calling Tasks */
        System.out.println("\n\n------->JAC 444 Assignment 1 <-------");
        
        System.out.println("\n\n------->Task 1 'Build Shapes From File' <-------\n");
        myShapes = buildShapesFromFile("Shapes.txt");
        
        System.out.println("\n\n------->Task 2 'Delete Triangle with min perimeter and Circle with max perimeter' <-------\n");
        deleteSomeShapes(myShapes);

        System.out.println("\n\n------->Task 3 'Calculate All Perimeter of Parallelograms ans All Perimeter of Triangles' <-------\n");
        allPerimeterFromShapes(myShapes);

        System.out.println("\n\n------->Task 4 'Print Sorted Shapes' <-------\n");
        printSortedShapes(myShapes);
    }

    /** 
     * Read data from a file and building Shapes from the data
     * @param fileName A string indicating the name of the source file
     * @return a List of Shapes indicating the built List of Shapes
     * */
    public static List<Shape> buildShapesFromFile(String fileName) {

        /** Path */
        String path = System.getProperty("user.dir");

        /** string to temporary store data from the file */
        String s;

        /** List to store Shapes from the file */
        List<Shape> myShapes = new LinkedList<Shape>();

        try (BufferedReader br = new BufferedReader(new FileReader(fileName))) { 
            while ((s = br.readLine()) != null) {
                String[] tok = s.split(",");

                //check the shape type and call the shape ctr.
                if (tok[0].equals("Circle")){
    
                    try{
                        Shape circle = new Circle(Double.parseDouble(tok[1]));
                        myShapes.add(circle);    
                    } catch(MyException e){
                        System.out.println(e.getMessage());
                    }

                } else if (tok[0].equals("Square")){
    
                    try{
                        Shape square = new Square(Double.parseDouble(tok[1]));
                        myShapes.add(square);    
                    } catch(MyException e){
                        System.out.println(e.getMessage());
                    }

                } else if (tok[0].equals("Rectangle")){
    
                    try{
                        Shape rectangle = new Rectangle(Double.parseDouble(tok[1]),Double.parseDouble(tok[2]));
                        myShapes.add(rectangle);    
                    } catch(MyException e){
                        System.out.println(e.getMessage());
                    }

                } else if (tok[0].equals("Parallelogram")){
    
                    try{
                        Shape parallelogram = new Parallelogram(Double.parseDouble(tok[1]),Double.parseDouble(tok[2]));
                        myShapes.add(parallelogram);    
                    } catch(MyException e){
                         System.out.println(e.getMessage());
                    }

                } else if (tok[0].equals("Triangle")){
    
                    try{
                        Shape triangle = new Triangle(Double.parseDouble(tok[1]),Double.parseDouble(tok[2]),Double.parseDouble(tok[2]));
                        myShapes.add(triangle);    
                    } catch(MyException e){
                         System.out.println(e.getMessage());
                    }

                }
             
            }    

            /** Print the list of Shapes built from the file */
            for (int i = 0; i < myShapes.size(); i++) {

                System.out.println(myShapes.get(i));

            }
        

        } catch (IOException e) {

            System.out.println(e.getMessage());

        }

        return myShapes;
    }

    /** 
     * Delete a Triangle with min perimeter and a Circle with max perimeter from the list
     * @param myShapes A List of Shapes indicating the list of Shapes
     * */
    public static void deleteSomeShapes(List<Shape> myShapes) { 

        /** List to store Triangles from the list of Shapes */
        List<Shape> myTriangles = new LinkedList<Shape>();

        /** List to store Circles from the list of Shapes */
        List<Shape> myCircles = new LinkedList<Shape>();

        /** minimum perimiter of Triangles */
        double minPerimeterTriangle;

        /** maximum perimiter of Circles */
        double maxPerimeterCircle;
       
        /** boolean to store if the Parallelogram was delited */
        boolean deleteParalelogram = false;

        /** boolean to store if the Circle was delited */
        boolean deleteCircle = false;

        /** Generatig a list of Triangles and a list of Circles from the list of Shapes */
        for (int i = 0; i < myShapes.size(); i++){

            if (myShapes.get(i).getClass().getName().equals("Triangle")){
                myTriangles.add(myShapes.get(i));
            } else if (myShapes.get(i).getClass().getName().equals("Circle")){
                myCircles.add(myShapes.get(i));
            }

        }

        /** Find Triangle with min perimeter */
        minPerimeterTriangle = myTriangles.get(0).getPerimeter();
        for (int i = 0; i < myTriangles.size(); i++){

            if (myTriangles.get(i).getPerimeter() < minPerimeterTriangle) {
               minPerimeterTriangle = myTriangles.get(i).getPerimeter();
            }

        }

        /** Find Circle with max perimeter */
        maxPerimeterCircle = myCircles.get(0).getPerimeter();
        for (int i = 0; i < myCircles.size(); i++){

            if (myCircles.get(i).getPerimeter() > maxPerimeterCircle) {
               maxPerimeterCircle = myCircles.get(i).getPerimeter();
            }

        }

        /** Deletes Triangles with min perimeter and Circles with max perimeter from the list of Shapes */
        
        /** Iterator for deleting */
        Iterator<Shape> shapesIterator = myShapes.iterator();

        while (shapesIterator.hasNext()) {

            /** Current element */
            Shape s = shapesIterator.next();

            if ((s.getClass().getName().equals("Triangle")) && (s.getPerimeter() == minPerimeterTriangle)){
                try{
                    shapesIterator.remove();
                    deleteParalelogram = true;
                } catch (ClassCastException | NullPointerException | UnsupportedOperationException e){
                    System.out.println(e.getMessage());
                };

            } else if ((s.getClass().getName().equals("Circle")) && (s.getPerimeter() == maxPerimeterCircle)){
                try{
                    shapesIterator.remove();
                    deleteCircle = true;
                } catch (ClassCastException | NullPointerException | UnsupportedOperationException e){
                    System.out.println(e.getMessage());
                };
            }

        }

        /** Print a Success message if the Shapes were deleted */
        if ( deleteParalelogram == true && deleteCircle == true){
            System.out.println("Shapes were successfully deleted.");
        }

    }

    /** 
     * Calculate All Perimeter of Parallelograms ans All Perimeter of Triangles
     * @param myShapes A List of Shapes indicating the list of Shapes
     * */
    public static void allPerimeterFromShapes(List<Shape> myShapes) {    
            
            /** all perimeter of Parallelograms */
            double allParallelogramsPerimiter = 0;

            /** all perimeter of Triangles */
            double allTrianglesPerimiter = 0;

            /** Calculate all perimiters for Parallelograms and Triangles */
            for (int i = 0; i < myShapes.size(); i++){
                if (myShapes.get(i).getClass().getName().equals("Parallelogram")){
                    allParallelogramsPerimiter = allParallelogramsPerimiter + myShapes.get(i).getPerimeter();
                }
                if (myShapes.get(i).getClass().getName().equals("Triangle")){
                    allTrianglesPerimiter = allTrianglesPerimiter + myShapes.get(i).getPerimeter();
                }
            }

            /** Print all perimiters for Parallelograms and Triangles */
            System.out.println(String.format("Perimeter of all Parallelograms = %.2f", allParallelogramsPerimiter));
            System.out.println(String.format("Perimeter of all Triangles = %.2f", allTrianglesPerimiter));
    
    }

    /** 
     * Sort a list of Shapes by class name, then by perimiter in ascending order within a class, and print the sorted list of Shapes
     * @param myShapes A List of Shapes indicating the list of Shapes
     * */
    public static void printSortedShapes(List<Shape> myShapes){

        /** Calling ShapeComparator for sorting the list of Shapes */
        myShapes.sort(ShapeComparator);

        /** Printing sorted Shapes*/
        for (int i = 0; i < myShapes.size(); i++) {

                System.out.println(myShapes.get(i));

        }
        

    }
}
