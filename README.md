# checkVAT

Verify the validity of a VAT number against the VIES database

## Example

```php
require "checkVAT.inc";

$vatNumber = "NL123456789B01";

if (checkVAT($vatNumber))
	echo "The entered VAT number is valid";
else
	echo "The entered VAT number is not valid";
```
