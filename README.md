# CS-300 DSA Final Project
## 1. What was the problem you were solving in the projects for this course?
The main problem I tackled in this course was designing a program to manage and display course information for a computer science department. Specifically, the project required:
- Reading a course data file into a suitable data structure.
- Providing users with the ability to view a sorted list of courses in alphanumeric order.
- Allowing users to search for individual courses and display their details, including prerequisites.
This project emphasized efficiency, accuracy, and scalability, requiring the selection of appropriate data structures to store and retrieve the course data effectively.

## 2. How did you approach the problem? Consider why data structures are important to understand.
I began by breaking the problem into smaller, manageable steps, such as file reading, data storage, sorting, and user interaction. Understanding data structures was crucial in deciding how to organize and retrieve the course data efficiently:

I used a hash table (std::unordered_map) to store course objects because it allows for constant-time lookups when accessing a course by its number. This was ideal for searching and retrieving course information quickly.
For sorting and displaying the course list, I extracted the keys (course numbers) from the hash table into a vector and sorted them using the standard sorting algorithm (std::sort).
This approach highlighted why data structures are foundational to software design: choosing the right data structure impacts performance, readability, and scalability.

## 3. How did you overcome any roadblocks you encountered while going through the activities or project?
One roadblock I faced was dealing with the lack of a default constructor for my Course class. When accessing a key in the hash table that did not exist, the program attempted to create a default Course object, leading to compiler errors. To resolve this:

- I added a default constructor to the Course class, ensuring that empty or uninitialized courses could be safely handled.
- I also added checks to verify if a key existed in the hash table before attempting to access it.
- Another challenge was ensuring that the program gracefully handled invalid or corrupted data files. I added validation checks when reading and parsing the file, such as ensuring each line had the correct number of fields and that prerequisites matched existing course numbers.

## 4. How has your work on this project expanded your approach to designing software and developing programs?
This project reinforced the importance of modularity and planning when designing software. By separating the program into distinct components—file handling, data parsing, sorting, and user interaction—I was able to:

- Write cleaner and more organized code.
- Isolate errors to specific parts of the program, making debugging easier.
- Reuse components like the Course class and file-reading logic in other contexts or programs.
Additionally, I learned the importance of choosing the right data structures to meet specific program requirements, balancing performance and code simplicity.

## 5. How has your work on this project evolved the way you write programs that are maintainable, readable, and adaptable?
Working on this project improved my ability to write programs that are both maintainable and readable. I accomplished this by:

- Using clear and descriptive naming conventions for variables, functions, and classes.
- Writing inline comments to explain key sections of the code, improving clarity for future readers (or myself when revisiting the code).
- Keeping functions focused on single responsibilities, which makes the program easier to extend or modify without breaking other components.
For adaptability, I designed the program in a way that allows future enhancements. For instance, the hash table and sorting logic could easily accommodate additional data fields or support alternative sorting options if needed.

## Final Thoughts
This project not only deepened my understanding of data structures like hash tables and vectors but also emphasized the importance of good coding practices in developing efficient, maintainable software. It has prepared me to approach future programming challenges with a clear strategy, ensuring scalability and readability while solving complex problems.

