Use Project4;
Select COUNT(OrderTotal), Quantity
From RETAIL_ORDER, ORDER_ITEM
WHERE   ORDER_ITEM.Quantity != 2 
GROUP BY Quantity
ORDER BY Quantity;
