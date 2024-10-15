import webbrowser
url = 'https://docs.python.org/'

# Open URL in a new tab, if a browser window is already open.
webbrowser.open_new_tab(url)

# Open URL in new window, raising the window if possible.
webbrowser.open_new(url)

driver = webdriver.Chrome(...)  # (Or Chrome(), or Ie(), or Opera() depends on which you are working on)

username = driver.find_element_by_id("username")

password = driver.find_element_by_id("password")

username.send_keys("YourUsername")

password.send_keys("PassworD")

driver.find_element_by_name("submit").click()
