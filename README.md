# samp-money-format
SAMP money formatting for a few Global Currencies

## Function

```pawn
FormatMoney(value, currency, enable_cent, enable_type);
```
```
(!) enable_cent. by enabling this, you will use last 2 digits from your amount values. ex amount: 14000 -> output: $140.00, default value: false
(!) enable_type. by enabling this, you will get full money format. ex amount: 14000 -> USD$140.00, default value: false

by defining MONEYFMT_ALWAYS_USECENT before including this, default value for enable_cent will be true
```

## Existing Currencies

```
MONEYFMT_USD (US Dollar)
MONEYFMT_EUR (Euro)
MONEYFMT_GBP (Pounds)
MONEYFMT_IDR (Rupiah)
MONEYFMT_JPY (Yen)
```

## Example How to use

FormatMoney
```pawn
#include <samp-money-format.inc>

main ()
{
    new
          money = 500000
    ;

    printf("%s", FormatMoney(money, MONEYFMT_EUR));
    // Expected output -> €500,000 (may declares unknown symbol since console doesn't supported several symbol like €)

    printf("%s", FormatMoney(money, MONEYFMT_IDR, _, true));
    // Expected output -> IDR500,000

    printf("%s", FormatMoney(money, MONEYFMT_USD, true, true));
    // Expected output -> USD$5,000.00
}
````
