import requests

def get_weather(city):
    api_key = ""YOUR_API_KEY_HERE"
    url = f"https://api.openweathermap.org/data/2.5/weather?q={city}&appid={api_key}&units=metric"

    response = requests.get(url)
    data = response.json()

    if response.status_code == 200:
        temperature = data["main"]["temp"]
        condition = data["weather"][0]["description"]

        print("\nWeather Details")
        print("----------------")
        print(f"City        : {city}")
        print(f"Temperature : {temperature} °C")
        print(f"Condition   : {condition.capitalize()}")
    else:
        print("\n❌ Error occurred")
        print("Status Code:", response.status_code)
        print("Message:", data.get("message", "No message"))


def main():
    print("🌤️ Simple Weather Application")
    city = input("Enter city name: ").strip()
    get_weather(city)

if __name__ == "__main__":
    main()
