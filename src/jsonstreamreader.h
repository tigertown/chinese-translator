#ifndef JSONSTREAMREADER_H
#define JSONSTREAMREADER_H

#include <QIODevice>

class THJsonStreamReaderPrivate;

class THJsonStreamReader {
        public:
                enum TokenType {
                        NoToken,
                        Invalid,
                        PropertyNumerical,
                        PropertyString,
                        PropertyFalse,
                        PropertyTrue,
                        PropertyNull,
                        Object,
                        ObjectEnd,
                        Array,
                        ArrayEnd
                };

        public:
                THJsonStreamReader();
                THJsonStreamReader (QIODevice *device);
                THJsonStreamReader (const QByteArray& data);
                THJsonStreamReader (const QString& data);
                THJsonStreamReader (const char *data);
                ~THJsonStreamReader();

                bool atEnd (void) const;
                TokenType readNext (void);

                QVariant value (void) const;
                QStringRef name (void) const;

                TokenType tokenType (void) const;
                TokenType parentTokenType (void) const;

                void clear (void);

                QIODevice *device (void) const;
                void setDevice (QIODevice *device);

                void addData (const QByteArray& data);
                void addData (const QString& data);
                void addData (const char *data);

        private:
                THJsonStreamReaderPrivate *d;
};

#endif // JSONSTREAMREADER_H
