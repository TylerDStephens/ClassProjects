Use Project4;
SELECT *
FROM RETAIL_ORDER INNER JOIN ORDER_ITEM
 ON(RETAIL_ORDER.OrderNumber = ORDER_ITEM.OrderNumber)


