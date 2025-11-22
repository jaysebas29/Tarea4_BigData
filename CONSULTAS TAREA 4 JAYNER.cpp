//-----------------------------------------
// 1. INSERTAR DOCUMENTOS
//-----------------------------------------
 
db ["jugadores"].insertOne({
 
Team: "Testland",
 
"#": 99,
 
Pos: { "": "FW" },
 
"FIFA Popular Name": "Player Test",
 
"Birth Date": "01.01.2000",
 
"Shirt Name": "TEST",
 
Club: "Test Club (TST)",
 
Height: 185,
 
Weight: 80
});
 
//-----------------------------------------
// 2. CONSULTA DE SELECCION (FIND)
//-----------------------------------------
 
db ["jugadores"].find({ Team: "France" })
 
//-----------------------------------------
// 3. CONSULTA DE ACTUALIZACION (UPDATE)
//-----------------------------------------
 
db ["jugadores"].updateOne(
 
{ "FIFA Popular Name": "LEMAR Thomas" },
 
{ $set: { Weight: 66 }}
 
);
 
//-----------------------------------------
// 4. CONSULTA DE ELIMINACION (DELETE)
//-----------------------------------------
 
db["jugadores"].deleteOne({ Team: "Testland" });
 
 
//-----------------------------------------
// 5. CONSULTA CON FILTROS Y OPERADORES
//-----------------------------------------
 
db["jugadores"].find({ Height: { $gt: 180 } });

db["jugadores"].find({ Team: "Portugal", Height: { $gte: 180 } });
 

//-----------------------------------------
// 6. AGREGACION: total de jugadores por pais 
//-----------------------------------------
 
db["jugadores"].aggregate([
 
{$group: {_id: "$Team", total: { $sum: 1}}}]);

 
//-----------------------------------------
// 7. AGREGACION: altura promedio por pais
//-----------------------------------------
 
db["jugadores"].aggregate([
 
{$group: {_id: "$Team", altura_promedio: { $avg: "$Height"}}}]);

 
//-----------------------------------------
// 8. AGREGACION: total de jugadores por posicion 
//-----------------------------------------
 
db["jugadores"].aggregate([
 
{
 
$group: {
 
_id: "$Pos",
 
total_jugadores: { $sum: 1}
 
}
 
}
 
])


//-----------------------------------------
// 9. AGREGACION: jugador con mas peso de cada pais
//-----------------------------------------
db["jugadores"].aggregate([
  {
    $sort: { Weight: -1 }   // Ordenar de mayor a menor peso
  },
  {
    $group: {
      _id: "$Team",
      jugador_mas_pesado: { $first: "$FIFA Popular Name" },
      peso: { $first: "$Weight" }
    }
  }
]) 