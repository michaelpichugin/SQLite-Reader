#pragma once
using namespace System;

ref class Alloys abstract {
public:
	Alloys();
	Alloys(String^, String^, String^, String^, double, double);
	Alloys(const Alloys^);
	virtual String^ getInfo() = 0;
	virtual String^ getId() = 0;
	virtual String^ getMaterial() = 0;
	virtual String^ getCategory() = 0;
	virtual String^ getContent() = 0;
	virtual String^ getStructure() = 0;
	virtual double getMeltingtemp() = 0;
	virtual double getDensity() = 0;
	virtual void setId(String^) = 0;
	virtual void setMaterial(String^) = 0;
	virtual void setCategory(String^) = 0;
	virtual void setContent(String^) = 0;
	virtual void setMeltingtemp(double) = 0;
	virtual void setDensity(double) = 0;
	virtual void setStructure(String^) = 0;
protected:
	String^ id;
	String^ material;
	String^ category;
	String^ content;
	double meltingtemp;
	double density;
};

Alloys::Alloys() {
	id = "1";
	material = "Бронза";
	category = "Чёрные металлы";
	content = "Сплав меди с оловом";
	meltingtemp = 930;
	density = 8000;
}

Alloys::Alloys(const Alloys^ a) {
	id = a->id;
	material = a->material;
	category = a->category;
	content = a->content;
	meltingtemp = a->meltingtemp;
	density = a->density;
}

Alloys::Alloys(String^ id, String^ material, String^ category, String^ content, double meltingtemp, double density) {
	this->id = id;
	this->material = material;
	this->category = category;
	this->content = content;
	this->meltingtemp = meltingtemp;
	this->density = density;
}