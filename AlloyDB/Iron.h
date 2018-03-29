#pragma once
#include "Alloys.h"

ref class Iron : public Alloys {
public:
	Iron();
	Iron(String^, String^, String^, String^, double, double, String^);
	Iron(const Iron^);
	virtual ~Iron();
	virtual String^ getInfo() override;
	virtual String^ getId() override;
	virtual String^ getMaterial() override;
	virtual String^ getCategory() override;
	virtual String^ getContent() override;
	virtual String^ getStructure() override;
	virtual double getMeltingtemp() override;
	virtual double getDensity() override;
	virtual void setId(String^) override;
	virtual void setMaterial(String^) override;
	virtual void setCategory(String^) override;
	virtual void setContent(String^) override;
	virtual void setMeltingtemp(double) override;
	virtual void setDensity(double) override;
	virtual void setStructure(String^) override;
private:
	String^ structure;
};

Iron::Iron() {
	id = "";
	material = "";
	category = "";
	content = "";
	meltingtemp = 0.0;
	density = 0.0;
	structure = "";
}

Iron::Iron(String^ id, String^ material, String^ category,
	String^ content, double meltingtemp, double density, String^ structure) {
	this->id = id;
	this->material = material;
	this->category = category;
	this->content = content;
	this->meltingtemp = meltingtemp;
	this->density = density;
	this->structure = structure;
}

Iron::Iron(const Iron^ a) {

}

Iron::~Iron() {}

String^ Iron::getInfo() {
	return (	"ID = "						+ id + "\r\n" 
			+	"Материал = "				+ material + "\r\n"
			+	"Категория = "				+ category + "\r\n" 
			+	"Содержание = "				+ content + "\r\n" 
			+	"Температура плавления = "	+ meltingtemp + "\r\n"
			+	"Плотность = "				+ density + "\r\n" 
			+	"Структура = "				+ structure + "\r\n");
}

String^ Iron::getId() { return id; }
String^ Iron::getMaterial() { return material; }
String^ Iron::getCategory() { return category; }
String^ Iron::getContent() { return content; }
String^ Iron::getStructure() { return structure; }
double Iron::getMeltingtemp() { return meltingtemp; }
double Iron::getDensity() { return density; }
void Iron::setId(String^ id) { this->id = id; }
void Iron::setMaterial(String^ material) { this->material = material; }
void Iron::setCategory(String^ category) { this->category = category; }
void Iron::setContent(String^ content) { this->content = content; }
void Iron::setMeltingtemp(double meltingtemp) { this->meltingtemp = meltingtemp; }
void Iron::setDensity(double density) { this->density = density; }
void Iron::setStructure(String^ structure) { this->structure = structure; }