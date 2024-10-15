from selenium import webdriver

from selenium.webdriver.common.by import By

options = webdriver.ChromeOptions()
options.add_experimental_option("detach", True)
# Create a new instance of the Chrome browser (you need ChromeDriver executable)
driver = webdriver.Chrome(options=options)

# Open the website
driver.get("https://codeforces.com/enter?back=%2F")

# Find the email and password fields and populate them
email_field = driver.find_element(By.ID, "handleOrEmail")
password_field = driver.find_element(By.ID, "password")

email_field.send_keys("sasta_samurai")
password_field.send_keys("codeforces@vandan")

# Find and click the login button
login_button = driver.find_element(By.ID, "Login")
login_button.click()

# Close the browser
# driver.quit()





