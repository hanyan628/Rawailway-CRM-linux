CREATE TABLE "record_day_passenger" (
	"statistics_date"	TEXT NOT NULL DEFAULT 00000000 UNIQUE,
	"HKN"	INTEGER NOT NULL DEFAULT 0,
	"HCN"	INTEGER NOT NULL DEFAULT 0,
	"TNN"	INTEGER NOT NULL DEFAULT 0,
	"XAN"	INTEGER NOT NULL DEFAULT 0,
	"QJN"	INTEGER NOT NULL DEFAULT 0,
	"JBN"	INTEGER NOT NULL DEFAULT 0,
	"ZJN"	INTEGER NOT NULL DEFAULT 0,
	"IHN"	INTEGER NOT NULL DEFAULT 0,
	"JTN"	INTEGER NOT NULL DEFAULT 0,
	"TJN"	INTEGER NOT NULL DEFAULT 0,
	"TEN"	INTEGER NOT NULL DEFAULT 0,
	"MJN"	INTEGER NOT NULL DEFAULT 0,
	"MHN"	INTEGER NOT NULL DEFAULT 0,
	"IYN"	INTEGER NOT NULL DEFAULT 0,
	"GDN"	INTEGER NOT NULL DEFAULT 0,
	"VTN"	INTEGER NOT NULL DEFAULT 0,
	PRIMARY KEY("statistics_date")
);

CREATE TABLE "record_day_revenue" (
	"statistics_date"	TEXT NOT NULL DEFAULT 00000000 UNIQUE,
	"HKN"	REAL NOT NULL DEFAULT 0.0,
	"HCN"	REAL NOT NULL DEFAULT 0.0,
	"TNN"	REAL NOT NULL DEFAULT 0.0,
	"XAN"	REAL NOT NULL DEFAULT 0.0,
	"QJN"	REAL NOT NULL DEFAULT 0.0,
	"JBN"	REAL NOT NULL DEFAULT 0.0,
	"ZJN"	REAL NOT NULL DEFAULT 0.0,
	"IHN"	REAL NOT NULL DEFAULT 0.0,
	"JTN"	REAL NOT NULL DEFAULT 0.0,
	"TJN"	REAL NOT NULL DEFAULT 0.0,
	"TEN"	REAL NOT NULL DEFAULT 0.0,
	"MJN"	REAL NOT NULL DEFAULT 0.0,
	"MHN"	REAL NOT NULL DEFAULT 0.0,
	"IYN"	REAL NOT NULL DEFAULT 0.0,
	"GDN"	REAL NOT NULL DEFAULT 0.0,
	"VTN"	REAL NOT NULL DEFAULT 0.0,
	PRIMARY KEY("statistics_date")
);