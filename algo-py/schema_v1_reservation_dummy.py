import os
import datetime
import itertools
from random import shuffle, randrange

reservation_value = 800_0000
customer_value = 100_0000
product_value = 5_000


products = [i for i in range(1, 5001)]
products_cycle = itertools.cycle(products)
categorys = ['ACCOMMODATION', 'RESTAURANT', 'RENTAL_CAR']
categorys_cycle = itertools.cycle(categorys)
customers = [i for i in range(1, 100_0001)]
customers_cycle = itertools.cycle(customers)


def generate_dates(start_date, end_date):
    date_list = []
    current_date = start_date
    while current_date <= end_date:
        date_list.append(current_date)
        current_date += datetime.timedelta(days=1)

    shuffle(date_list)
    return date_list


start_date = datetime.datetime(2023, 1, 1)
end_date = datetime.datetime(2023, 10, 18)

all_dates = generate_dates(start_date, end_date)
date_cycle = itertools.cycle(all_dates)


os.mkdir("schema_v1_customer")
for step in range(1, customer_value // 5000 + 1):
    with open(f"schema_v1_customer/schema_v1_customer_dummy{step}.sql", "w", encoding="utf-8") as file:

            file.write("INSERT INTO customer (created_at, updated_at, kakao_id, name, partner_custom_id, phone_number, partner_company_id)\n")
            file.write("VALUES\n")
            for i in range(1 + (5000 * (step - 1)), 5000 * step):
                file.write(f"('2023-10-19T12:00:00', '2023-10-19T12:00:00', 'CUSTOMER_{i}', '권순찬', 'CUSTOMER_{i}', {i}, {i}, 1),\n")
            file.write(f"('2023-10-19T12:00:00', '2023-10-19T12:00:00', 'CUSTOMER_{i + 1}', '권순찬', 'CUSTOMER_{i + 1}', {i}, {i}, 1);\n")


os.mkdir("schema_v1_product")
for step in range(1, product_value // 5000 + 1):
    with open(f"schema_v1_product/schema_v1_product_dummy{step}.sql", "w", encoding="utf-8") as file:

            file.write("INSERT INTO travel_product (partner_custom_id, dtype, thumbnail_url, name, review_count, rating, category, created_at, updated_at, partner_company_id, partner_seller_id)\n")
            file.write("VALUES\n")
            for i in range(1 + (5000 * (step - 1)), 5000 * step):
                file.write(f"('CUSTOMER_{i}', 'SingleTravelProduct', 'test.url', '테스트', 1000, {randrange(1,6)}, '{next(categorys_cycle)}', '2023-08-30 12:00:00', '2023-08-30 12:00:00', 1, 1),\n")
            file.write(f"('CUSTOMER_{i + 1}', 'SingleTravelProduct', 'test.url', '테스트', 1000, {randrange(1,6)}, '{next(categorys_cycle)}', '2023-08-30 12:00:00', '2023-08-30 12:00:00', 1, 1);\n")


os.mkdir("schema_v1_reservation")
for step in range(1, reservation_value // 5000 + 1):
    with open(f"schema_v1_reservation/schema_v1_reservation_dummy{step}.sql", "w", encoding="utf-8") as file:

            file.write("INSERT INTO reservation (created_at, updated_at, partner_custom_id, start_date_time, end_date_time, travel_product_id, customer_id, review_id, live_satisfaction_id, live_feedback_id)\n")
            file.write("VALUES\n")
            for i in range(1 + (5000 * (step - 1)), 5000 * step):
                created_at = next(date_cycle)
                file.write(f"('{created_at}', '{created_at}', 'RESERVATION_{i}', '2023-10-18T13:00:00', '2023-10-19T12:00:00', {next(products_cycle)}, {next(customers_cycle)}, {i}, {i}, {i}),\n")
            created_at = next(date_cycle)
            file.write(f"('{created_at}', '{created_at}', 'RESERVATION_{i + 1}', '2023-10-18T13:00:00', '2023-10-19T12:00:00', {next(products_cycle)}, {next(customers_cycle)}, {i + 1}, {i + 1}, {i + 1});\n")