# Probabilistic cardinality estimation

Given a data stream with repeated elements count the number of distinct elements in having less memory than it is needed to store them all (use a [HashMap](https://en.wikipedia.org/wiki/Hash_table) for instance)

This is the well know computer science problem which is face during [YandexCup](https://en.wikipedia.org/wiki/Count-distinct_problem) programming challenge

#### *The original formulation*:
***
Users make tens of thousands of requests per second in Yandex.Search. Some of the requests are asked hundreds of times per hour, the other part of the requests is repeated several times a day, the third part of requests is asked by users from Yandex for the first time.

You need to estimate the number of unique requests, assuming you have 500 KB of RAM. It is guaranteed that the correct answer does not exceed 100,000 and is not less than 50,000.

The decision is valid if the answer differs from the correct one by no more than 5%.

__Input format__
The first line contains the number n≤500000 - the number of requests, among which you need to find the number of unique ones. Each of the next n lines contains one query. The length of each request does not exceed 1000 characters.



__Output format__
You need to output one number - an estimate of the number of unique requests. The score does not have to be integer.
***

### Solution
The idea comes from [here](http://highscalability.com/blog/2012/4/5/big-data-counting-how-to-count-a-billion-distinct-objects-us.html)

The exact task solution implements a **linear probabilistic counter** and can be found in `solution.cpp`. The rest of the project provides customizable handles for playing with various data sources and hash functiuons.

### UPD:
To use a web page as datasource you need to install *libcurl* from [here](https://curl.haxx.se/download.html)