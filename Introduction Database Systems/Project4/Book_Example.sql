Use Project4
Select *
FROM RETAIL_ORDER, ORDER_ITEM
WHERE RETAIL_ORDER.OrderNumber = ORDER_ITEM.OrderNumber
      ORDER BY RETAIL_ORDER.OrderNumber, ORDER_ITEM.SKU;