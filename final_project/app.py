import os
from flask import Flask, render_template, request, redirect, url_for, flash
from flask_sqlalchemy import SQLAlchemy

# Configure application
app = Flask(__name__)
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///budget.db'
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False
app.secret_key = 'your_secret_key'
db = SQLAlchemy(app)

# Database model
class Expense(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    description = db.Column(db.String(100), nullable=False)
    amount = db.Column(db.Float, nullable=False)

# Create database
with app.app_context():
    db.create_all()

@app.route('/')
def index():
    expenses = Expense.query.all()
    total_expenses = sum(expense.amount for expense in expenses)
    return render_template('index.html', expenses=expenses, total=total_expenses)

@app.route('/add_expense', methods=['GET', 'POST'])
def add_expense():
    if request.method == 'POST':
        description = request.form.get('description')
        amount = request.form.get('amount')

        if not description or not amount:
            flash('Please provide a description and amount.')
            return redirect(url_for('add_expense'))

        new_expense = Expense(description=description, amount=float(amount))
        db.session.add(new_expense)
        db.session.commit()
        flash('Expense added successfully!')
        return redirect(url_for('index'))

    return render_template('add_expense.html')

@app.route('/report')
def report():
    expenses = Expense.query.all()
    total_expenses = sum(expense.amount for expense in expenses)
    savings_suggestion = "Try to save 20% of your income each month."  # You can enhance this logic.
    return render_template('report.html', expenses=expenses, total=total_expenses, suggestion=savings_suggestion)

if __name__ == '__main__':
    app.run(debug=True)
