select Prices.product_id as product_id  , 
round(sum(prices.price*UnitsSold.units)/sum(UnitsSold.units) , 2) as average_price 
from prices 
join unitssold 
on Prices.product_id = UnitsSold.product_id 
and UnitsSold.purchase_date >= Prices.start_date 
and UnitsSold.purchase_date <= Prices.end_date 
group by prices.product_id ; 