# Budgeting Tool for Students
#### Video Demo: <https://youtu.be/w_Zj3uS96tk>
#### Description:

The **Budgeting Tool for Students** is a web-based application designed to help students manage their finances effectively. With the rising costs of education and living expenses, it is crucial for students to track their spending and savings. This application allows users to log their expenses, categorize them, and receive suggestions on potential savings. The tool aims to empower students to develop better financial habits and improve their overall financial literacy.

### Features

- **User Authentication**: Users can create an account and log in securely. This feature ensures that each user’s financial data remains private and secure.

- **Add Expenses**: The application allows users to easily input their expenses, including the amount, category (e.g., food, transportation, entertainment), and date. This functionality helps users keep a detailed record of their spending habits.

- **View Expense Reports**: Users can generate reports that summarize their expenses by category and date. This feature provides insights into spending patterns, allowing users to identify areas where they can cut back.

- **Savings Suggestions**: Based on the user’s spending patterns, the application can provide tailored suggestions for potential savings, helping students make informed financial decisions.

- **Responsive Design**: The application is built to work seamlessly on both desktop and mobile devices, ensuring accessibility for users on the go.

### Directory Structure

The project is organized into a clear directory structure to facilitate easy navigation and maintenance:


### File Descriptions

- **app.py**: This is the main Python file where the Flask application is defined. It includes routes for rendering templates, handling form submissions, and interacting with the SQLite database to store user data and expenses.

- **requirements.txt**: This file lists all the necessary Python packages required to run the application. Users can easily install these dependencies using pip.

- **templates/layout.html**: The base layout template that includes the header, footer, and links to static CSS files. Other templates extend this layout for a consistent look and feel.

- **templates/index.html**: The homepage where users can log in or register for a new account. It provides a user-friendly interface for starting their budgeting journey.

- **templates/add_expense.html**: This page allows users to input their expenses. It includes a form with fields for the expense amount, category, and date.

- **templates/report.html**: This page displays the user's expense reports, showcasing their spending habits in a visually appealing format, helping them to analyze their finances effectively.

- **static/style.css**: This file contains custom CSS styles to enhance the visual appearance of the application, making it more appealing and user-friendly.

### Design Choices

In designing the **Budgeting Tool for Students**, several key choices were made to ensure a functional and user-friendly application:

- **Flask Framework**: Flask was chosen as the web framework due to its simplicity and flexibility, making it ideal for a small-scale application like this. It allows for rapid development and easy integration with other technologies.

- **SQLite Database**: SQLite was selected for data storage because it is lightweight and does not require a separate server, making it convenient for development and deployment.

- **Responsive Design**: The application uses a responsive design approach to ensure usability across various devices. This design choice reflects the need for accessibility among students who often use mobile devices.

### Conclusion

The **Budgeting Tool for Students** aims to provide an essential service to students navigating their financial responsibilities. By allowing users to track their expenses, visualize spending patterns, and receive tailored savings suggestions, this application serves as a valuable resource in promoting financial literacy and responsible budgeting habits.

This README provides an overview of the project, including its features, structure, and design choices. The application is a work in progress, and future updates will include enhanced functionalities, such as integration with external financial services and advanced reporting features.

