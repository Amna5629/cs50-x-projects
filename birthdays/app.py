from flask import Flask, render_template, request, redirect
import sqlite3

app = Flask(__name__)

@app.route("/", methods=["GET", "POST"])
def index():
    # Connect to the database
    connection = sqlite3.connect("birthdays.db")
    cursor = connection.cursor()

    if request.method == "POST":
        # Get form data
        name = request.form["name"]
        month = request.form["month"]
        day = request.form["day"]

        # Insert the new birthday into the database
        cursor.execute("INSERT INTO birthdays (name, month, day) VALUES (?, ?, ?)", (name, month, day))
        connection.commit()

        # Redirect back to the home page
        return redirect("/")
    
    else:
        # Query all birthdays
        cursor.execute("SELECT name, month, day FROM birthdays")
        birthdays = cursor.fetchall()

        # Close the database connection
        connection.close()

        # Render the template with the data
        return render_template("index.html", birthdays=birthdays)

if __name__ == "__main__":
    app.run(debug=True)
