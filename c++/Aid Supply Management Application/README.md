## Aid Management Application (AMA)

When disaster hits an area, the most important thing is to be able provide the people affected with what they need as quickly and as efficiently possible.

This project is an application that manages the list of goods needed to be shipped to the area. The application is able to keep track of the quantity of items needed and quantity in hand, and store them in a file for future use.

The types of goods to be shipped in this situation are divided into two categories:
- Non-Perishable products, such as blankets and tents, that have no expiry date.
- Perishable products, such as food and medicine, that have an expiry date.

Example output:
```
Disaster Aid Supply Management Program
1- List products
2- Display product
3- Add non-perishable product
4- Add perishable product
5- Add to quantity of purchased products
6- Update product quantity
7- Delete product
8- Sort products
0- Exit program
> 1

 Row | SKU    | Product Name       | Cost  | QTY| Unit     |Need| Expiry
-----|--------|--------------------|-------|----|----------|----|----------
   1 | 132    |Banana              |   0.99|   6|Kilos     |  10|2015/05/13
   2 | 123    |Beans               |  12.00| 200|kg        | 200|2018/12/22
   3 | 1234   |Blanket             |  17.70| 400|Boxes     | 400|
   4 | 122    |Bucket              |  11.30| 150|          | 300|
   5 | 124    |Corn                |   4.00|   0|Packs     | 140|2018/04/03
   6 | 1234   |Milk                |   3.99|   3|bags      | 300|2015/10/04
   7 | 998    |Mosquito Nets       |  62.15|  10|bx of 100 | 300|
   8 | 3456   |Paper Cups          |   6.77| 100|packs     | 500|
   9 | 2345   |Rice                |  15.99|  30|Bags      | 500|2017/12/23
  10 | 200    |Sand Bags           |   3.38|  20|packs     |1000|
Press Enter to continue...

  11 | 5678   |Sugar               |   6.78|   0|1kg Bags  | 200|
  12 | 111    |Water Container     |  12.79| 100|packs     |5000|
---------------------------------------------------------------------------
Total cost of support: $14316.03

Press Enter to continue...

Disaster Aid Supply Management Program
1- List products
2- Display product
3- Add non-perishable product
4- Add perishable product
5- Add to quantity of purchased products
6- Update product quantity
7- Delete droduct
8- Sort Products
0- Exit program
> 2
Please enter the SKU: 200

Sku: 200
Name: Sand Bags
Price: 2.99
Price after tax: 3.38
Quantity On Hand: 20 packs
Quantity Needed: 1000

Press Enter to continue...

Disaster Aid Supply Management Program
1- List products
2- Display product
3- Add non-perishable product
4- Add perishable product
5- Add to quantity of purchased products
6- Update product quantity
7- Delete product
8- Sort products
0- Exit program
> 3

Sku: 999
Name: Blanket
Unit: items
Taxed? (y/n): y
Price: 12
Quantity On hand: 10
Quantity Needed: 15

Product added

Disaster Aid Supply Management Program
1- List products
2- Display product
3- Add non-perishable product
4- Add perishable product
5- Add to quantity of purchased products
6- Update product quantity
7- Delete product
8- Sort products
0- Exit program
> 1

 Row | SKU    | Product Name       | Cost  | QTY| Unit     |Need| Expiry
-----|--------|--------------------|-------|----|----------|----|----------
   1 | 132    |Banana              |   0.99|   6|Kilos     |  10|2015/05/13
   2 | 123    |Beans               |  12.00| 200|kg        | 200|2018/12/22
   3 | 1234   |Blanket             |  17.70| 400|Boxes     | 400|
   4 | 122    |Bucket              |  11.30| 150|          | 300|
   5 | 124    |Corn                |   4.00|   0|Packs     | 140|2018/04/03
   6 | 1234   |Milk                |   3.99|   3|bags      | 300|2015/10/04
   7 | 998    |Mosquito Nets       |  62.15|  10|bx of 100 | 300|
   8 | 3456   |Paper Cups          |   6.77| 100|packs     | 500|
   9 | 2345   |Rice                |  15.99|  30|Bags      | 500|2017/12/23
  10 | 200    |Sand Bags           |   3.38|  20|packs     |1000|
Press Enter to continue...

  11 | 5678   |Sugar               |   6.78|   0|1kg Bags  | 200|
  12 | 111    |Water Container     |  12.79| 100|packs     |5000|
  13 | 999    |Blanket             |  13.56|  10|items     |  15|
---------------------------------------------------------------------------
Total cost of support: $14451.63

Press Enter to continue...

Disaster Aid Supply Management Program
1- List products
2- Display product
3- Add non-perishable product
4- Add perishable product
5- Add to quantity of purchased products
6- Update product quantity
7- Delete droduct
8- Sort Products
0- Exit program
> 4

Sku: 888
Name: Bread
Unit: items
Taxed? (y/n): n
Price: 2
Quantity On hand: 10
Quantity Needed: 40
Expiry date (YYYY/MM/DD): 2017/05/10

Product added

Disaster Aid Supply Management Program
1- List products
2- Display product
3- Add non-perishable product
4- Add perishable product
5- Add to quantity of purchased products
6- Update product quantity
7- Delete product
8- Sort products
0- Exit program
> 1

 Row | SKU    | Product Name       | Cost  | QTY| Unit     |Need| Expiry
-----|--------|--------------------|-------|----|----------|----|----------
   1 | 132    |Banana              |   0.99|   6|Kilos     |  10|2015/05/13
   2 | 123    |Beans               |  12.00| 200|kg        | 200|2018/12/22
   3 | 1234   |Blanket             |  17.70| 400|Boxes     | 400|
   4 | 122    |Bucket              |  11.30| 150|          | 300|
   5 | 124    |Corn                |   4.00|   0|Packs     | 140|2018/04/03
   6 | 1234   |Milk                |   3.99|   3|bags      | 300|2015/10/04
   7 | 998    |Mosquito Nets       |  62.15|  10|bx of 100 | 300|
   8 | 3456   |Paper Cups          |   6.77| 100|packs     | 500|
   9 | 2345   |Rice                |  15.99|  30|Bags      | 500|2017/12/23
  10 | 200    |Sand Bags           |   3.38|  20|packs     |1000|
Press Enter to continue...

  11 | 5678   |Sugar               |   6.78|   0|1kg Bags  | 200|
  12 | 111    |Water Container     |  12.79| 100|packs     |5000|
  13 | 999    |Blanket             |  13.56|  10|items     |  15|
  14 | 888    |Bread               |   2.00|  10|items     |  40|2017/05/10
---------------------------------------------------------------------------
Total cost of support: $14471.63

Press Enter to continue...

Disaster Aid Supply Management Program
1- List products
2- Display product
3- Add non-perishable product
4- Add perishable product
5- Add to quantity of purchased products
6- Update product quantity
7- Delete droduct
8- Sort Products
0- Exit program
> 5

Please enter the SKU: 999

Sku: 999
Name: Blanket
Price: 12.00
Price after tax: 13.56
Quantity On Hand: 10 items
Quantity Needed: 15

Please enter the number of purchased items: 5

Updated!

Press Enter to continue...

Disaster Aid Supply Management Program
1- List products
2- Display product
3- Add non-perishable product
4- Add perishable product
5- Add to quantity of purchased products
6- Update product quantity
7- Delete product
8- Sort products
0- Exit program
> 1

 Row | SKU    | Product Name       | Cost  | QTY| Unit     |Need| Expiry
-----|--------|--------------------|-------|----|----------|----|----------
   1 | 132    |Banana              |   0.99|   6|Kilos     |  10|2015/05/13
   2 | 123    |Beans               |  12.00| 200|kg        | 200|2018/12/22
   3 | 1234   |Blanket             |  17.70| 400|Boxes     | 400|
   4 | 122    |Bucket              |  11.30| 150|          | 300|
   5 | 124    |Corn                |   4.00|   0|Packs     | 140|2018/04/03
   6 | 1234   |Milk                |   3.99|   3|bags      | 300|2015/10/04
   7 | 998    |Mosquito Nets       |  62.15|  10|bx of 100 | 300|
   8 | 3456   |Paper Cups          |   6.77| 100|packs     | 500|
   9 | 2345   |Rice                |  15.99|  30|Bags      | 500|2017/12/23
  10 | 200    |Sand Bags           |   3.38|  20|packs     |1000|
Press Enter to continue...

  11 | 5678   |Sugar               |   6.78|   0|1kg Bags  | 200|
  12 | 111    |Water Container     |  12.79| 100|packs     |5000|
  13 | 999    |Blanket             |  13.56|  15|items     |  15|
  14 | 888    |Bread               |   2.00|  10|items     |  40|2017/05/10
---------------------------------------------------------------------------
Total cost of support: $14539.43

Press Enter to continue...

Disaster Aid Supply Management Program
1- List products
2- Display product
3- Add non-perishable product
4- Add perishable product
5- Add to quantity of purchased products
6- Update product quantity
7- Delete droduct
8- Sort Products
0- Exit program
> 6

Please enter the SKU: 888

Sku: 888
Name: Bread
Price: 2.00
Price after tax: N/A
Quantity On Hand: 10 items
Quantity Needed: 40
Expiry date: 2017/05/10

Please enter the new item quantity: 30
Invalid Quantity value, please enter a value between 0 and 10.

Disaster Aid Supply Management Program
1- List products
2- Display product
3- Add non-perishable product
4- Add perishable product
5- Add to quantity of purchased products
6- Update product quantity
7- Delete droduct
8- Sort Products
0- Exit program
> 6

Please enter the SKU: 888

Sku: 888
Name: Bread
Price: 2.00
Price after tax: N/A
Quantity On Hand: 10 items
Quantity Needed: 40
Expiry date: 2017/05/10

Please enter the new item quantity: 5
Item quantity is set to 5.

Disaster Aid Supply Management Program
1- List products
2- Display product
3- Add non-perishable product
4- Add perishable product
5- Add to quantity of purchased products
6- Update product quantity
7- Delete droduct
8- Sort Products
0- Exit program
> 1

 Row | SKU    | Product Name       | Cost  | QTY| Unit     |Need| Expiry
-----|--------|--------------------|-------|----|----------|----|----------
   1 | 132    |Banana              |   0.99|   6|Kilos     |  10|2015/05/13
   2 | 123    |Beans               |  12.00| 200|kg        | 200|2018/12/22
   3 | 1234   |Blanket             |  17.70| 400|Boxes     | 400|
   4 | 122    |Bucket              |  11.30| 150|          | 300|
   5 | 124    |Corn                |   4.00|   0|Packs     | 140|2018/04/03
   6 | 1234   |Milk                |   3.99|   3|bags      | 300|2015/10/04
   7 | 998    |Mosquito Nets       |  62.15|  10|bx of 100 | 300|
   8 | 3456   |Paper Cups          |   6.77| 100|packs     | 500|
   9 | 2345   |Rice                |  15.99|  30|Bags      | 500|2017/12/23
  10 | 200    |Sand Bags           |   3.38|  20|packs     |1000|
Press Enter to continue...

  11 | 5678   |Sugar               |   6.78|   0|1kg Bags  | 200|
  12 | 111    |Water Container     |  12.79| 100|packs     |5000|
  13 | 999    |Blanket             |  13.56|  15|items     |  15|
  14 | 888    |Bread               |   2.00|   5|items     |  40|2017/05/10
---------------------------------------------------------------------------
Total cost of support: $14529.43

Press Enter to continue...

Disaster Aid Supply Management Program
1- List products
2- Display product
3- Add non-perishable product
4- Add perishable product
5- Add to quantity of purchased products
6- Update product quantity
7- Delete droduct
8- Sort Products
0- Exit program
> 7

Deleting product, Please enter the SKU: 888

Deleted!

Disaster Aid Supply Management Program
1- List products
2- Display product
3- Add non-perishable product
4- Add perishable product
5- Add to quantity of purchased products
6- Update product quantity
7- Delete droduct
8- Sort Products
0- Exit program
> 1

 Row | SKU    | Product Name       | Cost  | QTY| Unit     |Need| Expiry
-----|--------|--------------------|-------|----|----------|----|----------
   1 | 132    |Banana              |   0.99|   6|Kilos     |  10|2015/05/13
   2 | 123    |Beans               |  12.00| 200|kg        | 200|2018/12/22
   3 | 1234   |Blanket             |  17.70| 400|Boxes     | 400|
   4 | 122    |Bucket              |  11.30| 150|          | 300|
   5 | 124    |Corn                |   4.00|   0|Packs     | 140|2018/04/03
   6 | 1234   |Milk                |   3.99|   3|bags      | 300|2015/10/04
   7 | 998    |Mosquito Nets       |  62.15|  10|bx of 100 | 300|
   8 | 3456   |Paper Cups          |   6.77| 100|packs     | 500|
   9 | 2345   |Rice                |  15.99|  30|Bags      | 500|2017/12/23
  10 | 200    |Sand Bags           |   3.38|  20|packs     |1000|
Press Enter to continue...

  11 | 5678   |Sugar               |   6.78|   0|1kg Bags  | 200|
  12 | 111    |Water Container     |  12.79| 100|packs     |5000|
  13 | 999    |Blanket             |  13.56|  15|items     |  15|
---------------------------------------------------------------------------
Total cost of support: $14519.43

Press Enter to continue...

Disaster Aid Supply Management Program
1- List products
2- Display product
3- Add non-perishable product
4- Add perishable product
5- Add to quantity of purchased products
6- Update product quantity
7- Delete droduct
8- Sort Products
0- Exit program
> 8

Sorted!

Disaster Aid Supply Management Program
1- List products
2- Display product
3- Add non-perishable product
4- Add perishable product
5- Add to quantity of purchased products
6- Update product quantity
7- Delete droduct
8- Sort Products
0- Exit program
> 1

 Row | SKU    | Product Name       | Cost  | QTY| Unit     |Need| Expiry
-----|--------|--------------------|-------|----|----------|----|----------
   1 | 132    |Banana              |   0.99|   6|Kilos     |  10|2015/05/13
   2 | 123    |Beans               |  12.00| 200|kg        | 200|2018/12/22
   3 | 1234   |Blanket             |  17.70| 400|Boxes     | 400|
   4 | 999    |Blanket             |  13.56|  15|items     |  15|
   5 | 122    |Bucket              |  11.30| 150|          | 300|
   6 | 124    |Corn                |   4.00|   0|Packs     | 140|2018/04/03
   7 | 1234   |Milk                |   3.99|   3|bags      | 300|2015/10/04
   8 | 998    |Mosquito Nets       |  62.15|  10|bx of 100 | 300|
   9 | 3456   |Paper Cups          |   6.77| 100|packs     | 500|
  10 | 2345   |Rice                |  15.99|  30|Bags      | 500|2017/12/23
Press Enter to continue...

  11 | 200    |Sand Bags           |   3.38|  20|packs     |1000|
  12 | 5678   |Sugar               |   6.78|   0|1kg Bags  | 200|
  13 | 111    |Water Container     |  12.79| 100|packs     |5000|
---------------------------------------------------------------------------
Total cost of support: $14519.43

Press Enter to continue...

Disaster Aid Supply Management Program
1- List products
2- Display product
3- Add non-perishable product
4- Add perishable product
5- Add to quantity of purchased products
6- Update product quantity
7- Delete droduct
8- Sort Products
0- Exit program
> 0

Goodbye!!
```
