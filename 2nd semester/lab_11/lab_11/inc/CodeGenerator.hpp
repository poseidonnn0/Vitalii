/*
* CodeGenerator.hpp
*
* @created 20.04.2022 Vitaly Kondratev
*
*/
#ifndef __CODEGENERATOR_H__ 
#define __CODEGENERATOR_H__ 

#include <iostream> 
#include <string> 
namespace programmLanguage
{
    enum Lang
    {
        JAVA = 0,
        C_PLUS_PLUS = 1,
        PHP = 2,
        C_SHARP = 3,
        //JS = 4 
    };

    class CodeGenerator
    {
    public:
        CodeGenerator() {};

        virtual ~CodeGenerator() {};

        std::string CG() // CG = CodeGenerator 
        {
            return ("CodeGenerator: \n" + someCodeRelatedThing() + "\n");
        }
    protected:
        virtual std::string someCodeRelatedThing() = 0;
    };

    class JAVA_CG : public CodeGenerator // CG = CodeGenerator 
    {
    public:
        JAVA_CG() : CodeGenerator() {};
        virtual ~JAVA_CG() {};
    protected:
        std::string someCodeRelatedThing() override
        {
            return "public class MyFirstJavaProgram{ \n"
                "public static void main(String[]args){\n"
                "System.out.println(""Привет мир!""); };\n";
        }
    };

    class C_PLUS_PLUS_CG : public CodeGenerator // CG = CodeGenerator 
    {
    public:
        C_PLUS_PLUS_CG() : CodeGenerator() {};
        virtual ~C_PLUS_PLUS_CG() {};
    protected:
        std::string someCodeRelatedThing() override
        {
            return "int main() {\n"
                "    std::cout << \"Hello World!\";\n"
                "    return 0;\n }";
        }
    };

    class PHP_CG : public CodeGenerator // CG = CodeGenerator 
    {
    public:
        PHP_CG() : CodeGenerator() {};
        virtual ~PHP_CG() {};
    protected:
        std::string someCodeRelatedThing() override
        {
            return "<!DOCTYPE html>\n"
                "< html >\n"
                "<head>\n"
                " <title>Пример< / title>\n"
                " < / head>\n"
                " <body>\n"
                " < ? php\n"
                " echo ""Привет, я - скрипт PHP!"";\n"
                "? >\n"
                " < / body>\n"
                " < / html>";
        }
    };

    class C_SHARP_CG : public CodeGenerator // CG = CodeGenerator 
    {
    public:
        C_SHARP_CG() : CodeGenerator() {};
        virtual ~C_SHARP_CG() {};
    protected:
        std::string someCodeRelatedThing() override
        {
            return "using System;\n"
                " namespace HelloWorld\n"
                "{ \n"
                " class Hello\n"
                "{ static void Main()\n"
                " { Console.WriteLine(""Hello World!"");\n"
                " } } }";
        }
    };

    std::shared_ptr<CodeGenerator> codeProgramm(enum Lang _language)
    {
        switch (_language)
        {

        case JAVA: return std::make_shared<JAVA_CG>();
        case C_PLUS_PLUS: return std::make_shared<C_PLUS_PLUS_CG>();
        case PHP: return std::make_shared<PHP_CG>();
        case C_SHARP: return std::make_shared<C_SHARP_CG>();

        default:
            throw std::logic_error("Bad language");
        }
    }

}
#endif