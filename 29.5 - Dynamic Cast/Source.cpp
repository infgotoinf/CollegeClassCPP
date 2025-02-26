#include <iostream>

class ISerializable
{
public:
	virtual ~ISerializable() = default;
	virtual void serialize() = 0;
};

class JsonSerializator : public ISerializable
{
public:
	void serialize() override
	{
		std::cout << "{ str : \"Hello World!\"; }";
	}
};

class XmlSerializator : public ISerializable
{
public:
	void serialize() override
	{
		std::cout << "<root><str>\"Hello World!\"</str></root>";
	}

	std::string toJson()
	{
		return "{ str : \"Hello World!\"; }";
	}
};

int main()
{
	ISerializable* ser;

	std::string opt;
	std::cin >> opt;

	if (opt == "json")
	{
		ser = new JsonSerializator;
	}
	else if (opt == "xml")
	{
		ser = new XmlSerializator;
	}
	else
	{
		std::cerr << "No such thing!" << std::endl;
		return 0;
	}
	ser->serialize();

	/*auto xmlSer = dynamic_cast<XmlSerializator*>(ser);

	if (xmlSer != nullptr)
	{
		std::cout << '\n' << xmlSer->toJson();
	}
	else
	{
		std::cout << '\n' << "Invalid cast!";
	}*/

	try
	{
		auto& xmlSer = dynamic_cast<XmlSerializator&>(*ser);
		std::cout << '\n' << xmlSer.toJson();
	}
	catch (std::bad_cast const& ex)
	{
		std::cerr << '\n' << ex.what();
	}

	delete ser;
}