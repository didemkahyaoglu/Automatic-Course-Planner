# Automatic-Course-Planner

  It is an automatic course planner for a curriculum semester of a department. In the curriculum, there are several courses for each year of the curriculum. Program will assign 
a classroom and a time slot for each course in the curriculum. 

•	Courses in the same year should not be intersected with each other. 

•	There can be some intersection between courses of different years. There are 2 different types of the classroom; big and small. Mandatory courses in the curriculum should be assigned to a big classroom. Elective courses can be assigned to a big or small classroom according to the availability of them. 

•	There is a limited number of dedicated classrooms for the department. The number of each type of classroom should be read from a file.

•	Besides, for each weekday there are 2-time slots available; morning and afternoon.  

  So there are in total 10 time slots available to place a course (5 weekdays*2 time slot).In the department curriculum, there are some service courses which are given by another 
department at the university. The time slot of these courses is fixed and predefined. Therefore, you cannot assign different time slots for those courses other than the requested 
time slot. Furthermore, some instructors may not available for some time slots. Thus, program should respect these busy time slots for the respective courses. 
All of these constraints should be taken from a file. You should not assume anything in prior and not use any hard-coded parameter / value in your code.In the end, program 
will produce a file that contains a course schedule for the department. In this schedule, there should not be any intersection between courses for a year of the curriculum and 
respect to all constraints. If program cannot find any possible schedule it will print a message “There is no way to make a perfect schedule for the department.” 
To fit the course schedule you may increase the number of classrooms via editing the file.
